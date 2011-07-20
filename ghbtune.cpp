#include "ghbtune.h"

#include <QGraphicsScene>

#include "ghbpitchlist.h"
#include "symbol.h"
#include "musicbar.h"
#include "melodynote.h"

GHBTune::GHBTune( QGraphicsScene *scene)
{
    m_pitchList = new GHBPitchList( 15.0 );

    //Ein paar Symbole in die Symbolliste
    m_symbols.append( new MelodyNote(scene, m_pitchList->getPitch(GHBPitchList::C)));
    m_symbols.append( new MelodyNote(scene, m_pitchList->getPitch(GHBPitchList::HighA)));

    //QPen um Elemente zu zeichnen
    QPen *pen = new QPen();
    pen->setWidthF(1.0);
    pen->setColor(Qt::black);

    //Vier Bars zeichnen
    qreal actual_x = 0;
    for( int i=0; i<4; i++ )
    {
        m_bars.append( new MusicBar( scene, m_pitchList ) );
        m_bars[i]->setPen(pen);
        m_bars[i]->setPos(actual_x, 0);
        actual_x += m_bars[i]->boundingRect().width() - pen->width();
    }
}

GHBTune::~GHBTune()
{
    delete m_pitchList;
}
