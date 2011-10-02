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
#ifndef PITCHLIST_H
#define PITCHLIST_H

#include <QtGlobal>
#include <QHash>

class Pitch;

class QString;

/*! @class PitchList
  * @brief A class that encapsulates a pitches for a instrument. So for example
  * the Great Highland Bagpipes has 9 pitches.
  * The pitches are stored in a QHash with integers as key. These are defined in
  * subclasses as enums for example.
  *
  * Every Pitch has a defined ypos in the MusicBar so you have to know about the 0-point of
  * the y-coordinate in the MusicBar.
  */
class PitchList
{
public:
    /*! @brief Constructor
      * @param lineHeight The lineHeight of the MusicBar
      */
    PitchList( qreal lineHeight );

    /*! @brief Destructor */
    ~PitchList();

    qreal lineHeight() const;

    /*! @return Pitch for the (enum) integer pitch */
    const Pitch *getPitch( int pitch ) const;

private:
    qreal m_lineHeight;

protected:
    /*! The hash, that stores the pitches. The integers should
      * be enums, defined in a subclass.
      */
    QHash<int, Pitch*> *m_pitches;
};

#endif // PITCHLIST_H
