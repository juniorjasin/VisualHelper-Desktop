#include "interface.hpp"
#include "ui_interface.h"

Interface::Interface( QWidget *parent ) : QWidget( parent ),
                                          ui( new Ui::Interface ),
                                          cameraWidget( new CameraWidget ),
                                          speechText("")
{
    this->setGraph( new Graph( this ) );
    this->setCamera( new Camera( this ) );
    this->setBlockSelectionTimer( new QTimer( this ) );
    this->setBlockSelection( false );
    this->setSpeaker( new Speech( this ) );

    ui->setupUi( this );
    ui->scrollArea->setFixedHeight( SCROLL_AREA_HEIGHT );
    this->setStyle();

    connect( this->ui->calibrateButton,
             SIGNAL( pressed() ),
             this->getCamera(),
             SLOT( calibrate() ) );

    connect( this->getCamera(),
             SIGNAL( positionDetected( int ) ),
             SLOT( activateBlock( int ) ) );

    connect( this->getCamera(),
             SIGNAL( selectionDetected( int ) ),
             SLOT( clickBlock( int ) ) );

    connect( blockSelectionTimer,
             SIGNAL( timeout() ),
             SLOT( unblockSelection() ) );


    connect( camera, SIGNAL( signal_newCameraFrame(cv::Mat*) ),
             cameraWidget, SLOT( slot_setCameraTexture(cv::Mat*) ) );

    connect( camera, SIGNAL( signal_nonFaceDetected() ),
             this, SLOT( phraseReset() ) );

//    ui->cameraWidget->setVisible( false );

}

Interface::~Interface()
{

}

void Interface::setStyle()
{
    this->setAutoFillBackground( true );

    QPalette palette( this->palette() );
    palette.setColor( QPalette::Background, Colorizer::getInstance()->getTheme()->getBackgroundColor() );
    palette.setColor( QPalette::WindowText, QColor( Qt::white ) );
    this->setPalette( palette );
}

void Interface::changeStyle()
{
     Colorizer::getInstance()->getNextTheme();

     QList< Block* > blocksList = this->findChildren< Block* >();
     for( int i = 0; i < blocksList.size(); i++ )
     {
         blocksList.at( i )->setStyle( false );
     }

     this->setStyle();
}


Graph *Interface::getGraph() const
{
    return graph;
}

void Interface::setGraph( Graph *value )
{
    graph = value;
}

Camera *Interface::getCamera() const
{
    return camera;
}

void Interface::setCamera( Camera *value )
{
    camera = value;
}

QTimer *Interface::getBlockSelectionTimer() const
{
    return blockSelectionTimer;
}

void Interface::setBlockSelectionTimer( QTimer *value )
{
    blockSelectionTimer = value;
}

bool Interface::getBlockSelection() const
{
    return blockSelection;
}

void Interface::setBlockSelection( bool value )
{
    blockSelection = value;
}

Speech *Interface::getSpeaker() const
{
    return speaker;
}

void Interface::setSpeaker( Speech *value )
{
    speaker = value;
}

bool Interface::initInterface( QFile *file )
{
    if( !this->getGraph()->initGraph( file ) )
    {
        // No se pudo iniciar el grafo
        qDebug() << "No se pudo iniciar el grafo";
        return false;
    }

    Nodo *initialNode = this->getGraph()->get( INITIAL_NODE_ID );

    if( !initialNode )
    {
        // No se encontro el nodo inicial
        qDebug() << "No se encontro el nodo inicial";
        return false;
    }

    this->createAndSet( initialNode );

    return true;
}

void Interface::keyPressEvent( QKeyEvent *event )
{
    switch( event->key() )
    {
    case Qt::Key_S:  // Cambia los colores de la interfaz
        this->changeStyle();
        break;

    case Qt::Key_I:  // Reinicia la frase
        this->phraseReset();
        break;

    case Qt::Key_C:  // Cambia de camara

        break;

    case Qt::Key_W:  // Mostrar el widget de la camara para ver que esta tomando
        if ( cameraWidget->isVisible() )  {
            cameraWidget->setParent(NULL);
//            cameraWidget->move( 0, this->height() );
            cameraWidget->hide();
        }
        else  {
//            cameraWidget->setWindowFlags( Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint | Qt::Window );
            cameraWidget->setWindowFlags( Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint );

            cameraWidget->resize( 640/4, 480/4 );
            cameraWidget->move( 10, this->height()-cameraWidget->height()-10 );

            // Le quitamos el focu para que no impida detectar las teclas
            cameraWidget->setFocusPolicy(Qt::NoFocus);

            cameraWidget->setParent(this);

            cameraWidget->show();
        }
        break;

    case Qt::Key_Escape:
        this->close();
        break;

    case Qt::Key_Space:  // Para calibrar. Igual a sonreir por primera vez, o pulsar el boton Calibrar
        this->getCamera()->calibrate();
        break;

    default:
        break;
    }
}

void Interface::resizeEvent(QResizeEvent *e)
{
//    cameraWidget->setWindowFlags( cameraWidget->windowFlags() | Qt::WindowStaysOnTopHint );
    cameraWidget->setWindowFlags( Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint );

    cameraWidget->resize( 640/4, 480/4 );
    cameraWidget->move( 10, e->size().height()-cameraWidget->height()-10 );

    // Le quitamos el focu para que no impida detectar las teclas
    cameraWidget->setFocusPolicy(Qt::NoFocus);

//    cameraWidget->show();
}

void Interface::createAndSet( Nodo *node )
{
    QList< Block* > blocksList = this->findChildren< Block* >();
    qDeleteAll( blocksList );

    this->ui->nodeTitleLabel->setText( node->getTitle() );

    if( node->getText() != "" )
    {
        QString sentence( ui->sentenceLabel->text() );
        sentence.append( " " );
        sentence.append( node->getText().toUpper() );
        this->ui->sentenceLabel->setText( sentence );

        speechText = removeAccents(sentence.replace(" ", " , "));
        QStringList signosIrreproducibles;
        signosIrreproducibles << "!" << "?" << "\u00BF" << "\u00A1" <<  "¡";
        speechText = removePunctuationCharacters(speechText, signosIrreproducibles);
    }

    if( node->getChildren().size() == 1 &&
        node->getChildren().at( 0 ) == "none" && !speechText.isEmpty() )
    {
        // reproduce la oracion en cada nueva seleccion de icon.
        this->getSpeaker()->read( speechText );
        return;
    }

    for( int i = 0; i < node->getChildren().size(); i++ )
    {
        Nodo *newNode = this->getGraph()->get( node->getChildren().at( i ) );

        if( newNode )
        {
            Block *block = new Block( newNode, this );
            this->ui->blocksLayout->addWidget( block );
            connect( block, SIGNAL( clicked( Nodo* ) ), SLOT( createAndSet( Nodo* ) ) );
        }
    }

    this->getCamera()->setSize( node->getChildren().size() );
}

// remueve los acentos de las palabaras que vienen como parametro
QString Interface::removeAccents(QString s){
    QString diacriticLetters_;
    QStringList noDiacriticLetters_;


    if (diacriticLetters_.isEmpty()) {
        diacriticLetters_ = QString::fromUtf8("ŠŒŽšœžŸ¥µÀÁÂÃÄÅÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖØÙÚÛÜÝßàáâãäåæçèéêëìíîïðñòóôõöøùúûüýÿ");
        noDiacriticLetters_ << "S"<<"OE"<<"Z"<<"s"<<"oe"<<"z"<<"Y"<<"Y"<<"u"<<"A"<<"A"<<"A"<<"A"<<"A"<<"A"<<"AE"<<"C"<<"E"<<"E"<<"E"<<"E"<<"I"<<"I"<<"I"<<"I"<<"D"<<"N"<<"O"<<"O"<<"O"<<"O"<<"O"<<"O"<<"U"<<"U"<<"U"<<"U"<<"Y"<<"s"<<"a"<<"a"<<"a"<<"a"<<"a"<<"a"<<"ae"<<"c"<<"e"<<"e"<<"e"<<"e"<<"i"<<"i"<<"i"<<"i"<<"o"<<"n"<<"o"<<"o"<<"o"<<"o"<<"o"<<"o"<<"u"<<"u"<<"u"<<"u"<<"y"<<"y";
    }

    QString output = "";
    for (int i = 0; i < s.length(); i++) {
        QChar c = s[i];
        int dIndex = diacriticLetters_.indexOf(c);
        if (dIndex < 0) {
            output.append(c);
        } else {
            QString replacement = noDiacriticLetters_[dIndex];
            output.append(replacement);
        }
    }

    return output;
}

// remueve los signos/palabras de s que y que estan en ls
QString Interface::removePunctuationCharacters(QString s,QStringList ls){
    for(int i = 0; i < ls.length(); i++)
        s = s.replace(ls.at(i), "");
    return s;
}

QString Interface::getSpeechText() const
{
    return speechText;
}

void Interface::setSpeechText(const QString &value)
{
    speechText = value;
}

/**
 * @brief Interface::activateBlock Ilumina el boton en la posicion index. Si es -1, desilumina todos.
 * @param index
 */
void Interface::activateBlock( int index )
{
    QList< Block* > blocksList = this->findChildren< Block* >();
    if( index >= 0 && index < blocksList.size() )
    {
        for( int i = 0; i < blocksList.size(); i++ )
        {
            blocksList.at( i )->setActive( false );
        }
        blocksList.at( index )->setActive( true );
    }
    else if ( index == -1 )  {
        for( int i = 0; i < blocksList.size(); i++ )
        {
            blocksList.at( i )->setActive( false );
        }
    }

}

void Interface::clickBlock( int index )
{
    if( !this->getBlockSelection() )
    {
        QString sound( APPLICATION_PATH );
        sound.append( SOUNDS_PATH );
        sound.append( "selected.wav" );
        QSound::play( sound );

        QList< Block* > blocksList = this->findChildren< Block* >();
        if( index >= 0 && index < blocksList.size() )
        {
            blocksList.at( index )->simulateClick();
        }

        this->setBlockSelection( true );
        blockSelectionTimer->start( 1000 );
    }
}

void Interface::unblockSelection()
{
    blockSelectionTimer->stop();
    this->setBlockSelection( false );
}

void Interface::phraseReset()
{
    this->ui->sentenceLabel->clear();
    this->createAndSet( this->getGraph()->get( INITIAL_NODE_ID ) );
}













