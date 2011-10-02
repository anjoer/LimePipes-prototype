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
#ifndef PITCH_H
#define PITCH_H

#include <QtGlobal>
#include <QHash>

class QString;
/*! @class Pitch
  * @brief A class that encapsulates a specific pitch.
  *
  * It has a defined ypos in the MusicBar so you have to know about the 0-point of
  * the y-coordinate in the bar. It also has a lineHeight for convenience, so that
  * music-symbols with a pitch member variable know about that for drawing.
  * Like a linked list, every pitch has a pointer to the next higher an lower pitch.
  *
  */
class Pitch
{
public:
    /*! @brief Constructor
      * @param name The name of the Pitch for example "Low A" for the Great Highland Bagpipe.
      * @param ypos The y-position in the MusicBar.
      * @param lineHeight The line height of the lines in the MusicBar.
      * @param desc An optional description of the pitch
      */
    Pitch( const char *name, qreal ypos, qreal lineHeight, QString *desc = 0 );

    /*! @brief Destructor */
    ~Pitch();

    /*! @return The y-position in the MusicBar */
    qreal y() const;
    const QString name() const;
    const QString description() const;
    qreal lineHeight() const;

    /*! @return The next higher pitch */
    const Pitch *nextHigher() const;

    /*! @return The next lower pitch */
    const Pitch *nextLower() const;

    /*! Set pointer to next higher pitch */
    void setNextHigher( const Pitch *pitch );

    /*! Set pointer to next lower pitch */
    void setNextLower( const Pitch *pitch );


private:
    /*! @brief The name of the pitch */
    const QString *m_name;

    /*! @brief The y-position in the MusicBar */
    const qreal m_yposition;

    /*! @brief The line height of the MusicBar */
    const qreal m_lineHeight;

    /*! @brief A description of the pitch. Maybe like
      * lift index, middle an ring-finger of right hand for that pitch
      */
    const QString *m_description;

    /*! @brief Pointer to next higher pitch */
    const Pitch *m_nextHigher;

    /*! @brief Pointer to next lower pitch */
    const Pitch *m_nextLower;

};

#endif // PITCH_H
