#include "speech.hpp"

#include <QDebug>

Speech::Speech( QObject *parent ) :
    QObject( parent )
{

}

int Speech::SynthCallback( short *wav, int numsamples, espeak_EVENT *events )
{
    Q_UNUSED( wav );
    Q_UNUSED( numsamples );
    Q_UNUSED( events );
    return 0;
}

void Speech::read( QString text )
{
    espeak_ERROR speakErr;

    if( espeak_Initialize( AUDIO_OUTPUT_SYNCH_PLAYBACK,
                           0,
                           NULL,
                           espeakINITIALIZE_PHONEME_EVENTS ) < 0 )
    {
        // No se pudo inicializar
        qDebug() << "No se pudo inicializar";
        return;
    }

    char textBuff[255] = { 0 };
    strcpy( textBuff, text.toStdString().c_str() );

    //espeak_PARAMETER esParam;
    //espeak_GetParameter(esParam, 0);

    espeak_VOICE *voice_spec = espeak_GetCurrentVoice(); // tomo el speak_VOICE actual y lo modifico.
    voice_spec->name=NULL;
    voice_spec->age = 20;
    voice_spec->gender= 1;
    voice_spec->languages = "es-la";
    voice_spec->variant = 0;

    espeak_SetVoiceByProperties(voice_spec);


    if( ( speakErr = espeak_Synth( textBuff,
                                   strlen(textBuff),
                                   0,
                                   POS_SENTENCE,
                                   0,
                                   espeakCHARS_8BIT,
                                   NULL,
                                   NULL ) ) != EE_OK )
    {
        qDebug() << "Error en la sintesis";
        // Error en la sintesis
        return;
    }

    espeak_Terminate();
}

