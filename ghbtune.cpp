/**
 * @file
 * @author  Thomas Baumann <teebaum@ymail.com>
 *
 * @section LICENSE
 *
 * <h3>GNU General Public License version 3</h3>
 * This program is free software; you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software Foundation;
 * either version 3 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with this program;
 * if not, see <http://www.gnu.org/licenses/>.
 *
 */
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
    setMaximumSize( m_rect.width(), m_rect.height());

    m_pitchList = new GHBPitchList( 20.0 );

    m_layout = new QGraphicsLinearLayout();
    m_layout->setSpacing(0.0); /*! No space between MusicBars */
    m_layout->setContentsMargins(0.0, 0.0, 0.0, 0.0 );

    /*! QPen for drawing all items */
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

    /*! A few Symbols for the MusicBar */
    dynamic_cast<MusicBar*>(m_layout->itemAt(1))->append( new MelodyNote(scene, m_pen, m_pitchList->getPitch(GHBPitchList::LowG), NoteLength::Eighth));
    dynamic_cast<MusicBar*>(m_layout->itemAt(1))->append( new MelodyNote(scene, m_pen, m_pitchList->getPitch(GHBPitchList::LowA), NoteLength::Half));
    dynamic_cast<MusicBar*>(m_layout->itemAt(1))->append( new MelodyNote(scene, m_pen, m_pitchList->getPitch(GHBPitchList::B), NoteLength::Quarter));
    dynamic_cast<MusicBar*>(m_layout->itemAt(1))->append( new MelodyNote(scene, m_pen, m_pitchList->getPitch(GHBPitchList::C), NoteLength::Whole));
    dynamic_cast<MusicBar*>(m_layout->itemAt(1))->append( new MelodyNote(scene, m_pen, m_pitchList->getPitch(GHBPitchList::D), NoteLength::Sixteenth));
    dynamic_cast<MusicBar*>(m_layout->itemAt(1))->append( new MelodyNote(scene, m_pen, m_pitchList->getPitch(GHBPitchList::E), NoteLength::Thirtysecond));
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

