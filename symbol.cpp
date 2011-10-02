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
#include "symbol.h"
#include "pitch.h"
#include "notelength.h"

Symbol::Symbol( QGraphicsScene *scene, const QPen *pen, NoteLength *length )
    :QGraphicsWidget(), m_pitch(0), m_pen(pen)
{
    setVisible(false);
    m_scene = scene;
    m_length = length;
}

bool Symbol::hasPitch() const
{
    return false;
}

bool Symbol::hasLength() const
{
    return false;
}

void Symbol::setPitch(const Pitch *pitch)
{
    if( this->hasPitch() )
    {
        m_pitch = pitch;
    }
}

const Pitch *Symbol::pitch() const
{
    return m_pitch;
}

const NoteLength *Symbol::length() const
{
    if( this->hasLength() )
    {
        return m_length;
    } else
    {
        return 0;
    }
}

void Symbol::setNextSymbol( const Symbol *symbol )
{
    m_nextSymbol = symbol;

}

void Symbol::setPrevSymbol(const Symbol *symbol)
{
    m_prevSymbol = symbol;
}

void Symbol::setLength( NoteLength *length)
{
    if( this->hasLength() )
    {
        m_length = length;
    }
}
