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
#include "notelength.h"
#include <QDebug>

NoteLength::NoteLength(Length length)
    :m_length(length)
{
    m_lengthVector.append(Thirtysecond);
    m_lengthVector.append(Sixteenth);
    m_lengthVector.append(Eighth);
    m_lengthVector.append(Quarter);
    m_lengthVector.append(Half);
    m_lengthVector.append(Whole);

    m_count = m_lengthVector.size();
    m_length = length;
}

NoteLength::Length NoteLength::length() const
{
    return m_length;
}

void NoteLength::setLength(Length length)
{
    m_length = length;
}

NoteLength NoteLength::operator++(int)
{
    Length oldLength = m_length;
    int idx = m_lengthVector.indexOf(m_length);
    if(idx != -1){  //Length existing?
        if(idx != m_count-1){ //More lengths existing?
            idx++;
            m_length = m_lengthVector.at(idx);
        }
    }
    return oldLength;
}

NoteLength NoteLength::operator--(int)
{
    Length oldLength = m_length;
    int idx = m_lengthVector.indexOf(m_length);
    if(idx != -1){  //Length existing?
        if(idx != 0){ //More lengths existing?
            idx--;
            m_length = m_lengthVector.at(idx);
        }
    }
    return oldLength;
}
