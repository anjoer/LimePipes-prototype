#include "ghbtune.h"

#include <QGraphicsScene>
#include <QDebug>

#include "ghbpitchlist.h"
#include "symbol.h"
#include "musicbar.h"
#include "melodynote.h"

#include <QGraphicsLinearLayout>

GHBTune::GHBTune( QGraphicsScene *scene)
    :QGraphicsWidget()
{
    m_rect = QRectF( 0, 0, 1500, 2000 );
    setMinimumSize( m_rect.width(), m_rect.height() );
    setPreferredSize(m_rect.width(), m_rect.height());
    setMaximumSize( m_rect.width(), m_rect.height())
            ;
    m_pitchList = new GHBPitchList( 20.0 );
    m_layout = new QGraphicsLinearLayout();
    m_layout->setSpacing(0.0);
    m_layout->setContentsMargins(0.0, 0.0, 0.0, 0.0 );

    //QPen um Elemente zu zeichnen
    m_pen = new QPen();
    m_pen->setWidthF(1.0);
    m_pen->setColor(Qt::black);

    scene->addItem(this);

    for( int i=0; i<4; i++ )
    {
        MusicBar *t_bar = new MusicBar(scene, m_pitchList, m_pen);
        m_layout->addItem(t_bar);
    }

    setLayout(m_layout);

    //Ein paar Symbole in die MusicBar
    dynamic_cast<MusicBar*>(m_layout->itemAt(1))->append( new MelodyNote(scene, m_pen, m_pitchList->getPitch(GHBPitchList::LowG)));
    dynamic_cast<MusicBar*>(m_layout->itemAt(1))->append( new MelodyNote(scene, m_pen, m_pitchList->getPitch(GHBPitchList::LowA)));
    dynamic_cast<MusicBar*>(m_layout->itemAt(1))->append( new MelodyNote(scene, m_pen, m_pitchList->getPitch(GHBPitchList::B)));
    dynamic_cast<MusicBar*>(m_layout->itemAt(1))->append( new MelodyNote(scene, m_pen, m_pitchList->getPitch(GHBPitchList::C)));
    dynamic_cast<MusicBar*>(m_layout->itemAt(1))->append( new MelodyNote(scene, m_pen, m_pitchList->getPitch(GHBPitchList::D)));
    dynamic_cast<MusicBar*>(m_layout->itemAt(1))->append( new MelodyNote(scene, m_pen, m_pitchList->getPitch(GHBPitchList::E)));
    dynamic_cast<MusicBar*>(m_layout->itemAt(1))->append( new MelodyNote(scene, m_pen, m_pitchList->getPitch(GHBPitchList::F)));
    dynamic_cast<MusicBar*>(m_layout->itemAt(1))->append( new MelodyNote(scene, m_pen, m_pitchList->getPitch(GHBPitchList::HighG)));
    dynamic_cast<MusicBar*>(m_layout->itemAt(1))->append( new MelodyNote(scene, m_pen, m_pitchList->getPitch(GHBPitchList::HighA)));
}

GHBTune::~GHBTune()
{
    delete m_pitchList;
}


QRectF GHBTune::boundingRect() const
{
    const double hpw = m_pen->widthF()/2;
    return m_rect.adjusted( -hpw, -hpw, hpw, hpw );
}


QSizePolicy GHBTune::sizePolicy() const
{
    return QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

