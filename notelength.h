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
#ifndef NOTELENGTH_H
#define NOTELENGTH_H

#include <QVector>

/*!
  * @class NoteLength
  * @brief A class that encapsulates the length of a @ref MelodyNote.
  *
  */
class NoteLength
{
public:
    /*! The NoteLengths */
    enum Length{
        NoLength=0, /*!< The length for all Symbols except MelodyNotes */
        Whole=1,    /*!< A whole length */
        Half=2,     /*!< A half length */
        Quarter=4,  /*!< A quarter length */
        Eighth=8,   /*!< A eighth length */
        Sixteenth=16, /*!< A sixteenth length */
        Thirtysecond=32 /*! A thirtysecond length */
    };
    /*! @brief Constructor
      * @param length The note-length
      */
    NoteLength( Length length );


    void setLength( Length length );
    NoteLength::Length length() const;
    /*! Overloaded increment operator to increase the note length. */
    NoteLength operator++(int);
    /*! Overloaded decrement operator to decrease the note length. */
    NoteLength operator--(int);

private:
    /*! @brief A vector with all lengths in it. Its easier to get the
      * next lower/higher length for the decrement/increment operator than
      * using switch/case. It was good for me to use QVector for practise ;).
      */
    QVector<Length> m_lengthVector;
    /*! @brief The actual length */
    Length m_length;
    /*! @brief The size of the vector.
      * @todo Is there a use for that?
      */
    int m_count;
};

#endif // NOTELENGTH_H
