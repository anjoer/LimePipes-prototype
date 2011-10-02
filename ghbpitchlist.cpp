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
#include "ghbpitchlist.h"
#include "pitch.h"

GHBPitchList::GHBPitchList( qreal lineHeight )
    :PitchList(lineHeight)
{
    m_pitches->insert(LowG, new Pitch("Low G", 3 * lineHeight, lineHeight ));
    m_pitches->insert(LowA, new Pitch("Low A", 2.5 * lineHeight, lineHeight  ));
    m_pitches->insert(B, new Pitch("B", 2.0 * lineHeight, lineHeight  ));
    m_pitches->insert(C, new Pitch("C", 1.5 * lineHeight, lineHeight  ));
    m_pitches->insert(D, new Pitch("D", 1.0 * lineHeight, lineHeight  ));
    m_pitches->insert(E, new Pitch("E", 0.5 * lineHeight, lineHeight  ));
    m_pitches->insert(F, new Pitch("F", 0.0, lineHeight  ));
    m_pitches->insert(HighG, new Pitch("High G", -0.5 * lineHeight, lineHeight  ));
    m_pitches->insert(HighA, new Pitch("High A", -1.0 * lineHeight, lineHeight  ));

    (*m_pitches)[LowG]->setNextHigher( (*m_pitches)[LowA] );

    (*m_pitches)[LowA]->setNextLower( (*m_pitches)[LowG] );
    (*m_pitches)[LowA]->setNextHigher( (*m_pitches)[B] );

    (*m_pitches)[B]->setNextLower( (*m_pitches)[LowA] );
    (*m_pitches)[B]->setNextHigher( (*m_pitches)[C] );

    (*m_pitches)[C]->setNextLower( (*m_pitches)[B] );
    (*m_pitches)[C]->setNextHigher( (*m_pitches)[D] );

    (*m_pitches)[D]->setNextLower( (*m_pitches)[C] );
    (*m_pitches)[D]->setNextHigher( (*m_pitches)[E] );

    (*m_pitches)[E]->setNextLower( (*m_pitches)[D] );
    (*m_pitches)[E]->setNextHigher( (*m_pitches)[F] );

    (*m_pitches)[F]->setNextLower( (*m_pitches)[E] );
    (*m_pitches)[F]->setNextHigher( (*m_pitches)[HighG] );

    (*m_pitches)[HighG]->setNextLower( (*m_pitches)[F] );
    (*m_pitches)[HighG]->setNextHigher( (*m_pitches)[HighA] );

    (*m_pitches)[HighA]->setNextLower( (*m_pitches)[HighG] );
}


