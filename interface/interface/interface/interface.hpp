#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#define INITIAL_NODE_ID "inicio"

#include <QWidget>
#include <QPalette>
#include <QList>
#include <QKeyEvent>
#include <QSound>
#include <QDebug>
#include <QString>

#include "graph/graph.hpp"
#include "theme/colorizer.hpp"
#include "interface/block.hpp"
#include "processor/camera.hpp"
#include "interface/camerawidget.h"

#include "common.hpp"
#include "speech.hpp"

namespace Ui
{
    class Interface;
}

class Interface : public QWidget
{
    Q_OBJECT

private:

    Ui::Interface *ui;
    Graph *graph;
    Camera *camera;

    QTimer *blockSelectionTimer;
    bool blockSelection;

    void setStyle();
    void changeStyle();

    Speech *speaker;

    CameraWidget * cameraWidget;

    // mis metodos
    QString removeAccents(QString s);
    QString removePunctuationCharacters(QString s, QStringList ls);

    QString speechText;

public:

    explicit Interface( QWidget *parent = NULL );
    ~Interface();

    Graph *getGraph() const;
    void setGraph( Graph *value );

    Camera *getCamera() const;
    void setCamera( Camera *value );

    QTimer *getBlockSelectionTimer() const;
    void setBlockSelectionTimer( QTimer *value );

    bool getBlockSelection() const;
    void setBlockSelection( bool value );

    Speech *getSpeaker() const;
    void setSpeaker( Speech *value );

    bool initInterface( QFile *file );

    QString getSpeechText() const;
    void setSpeechText(const QString &value);

protected:

    void keyPressEvent( QKeyEvent *event );
    void resizeEvent( QResizeEvent * e );

private slots:

    void createAndSet( Nodo *node );
    void activateBlock( int index );
    void clickBlock( int index );
    void unblockSelection();
    void phraseReset();
};

#endif // INTERFACE_HPP

