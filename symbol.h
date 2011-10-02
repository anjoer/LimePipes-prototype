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
#ifndef SYMBOL_H
#define SYMBOL_H

#include <QGraphicsWidget>
#include "notelength.h"

class Pitch;
class NoteLength;

/*! @class Symbol
  * @brief This is the baseclass of all symbols in a bar either visible or not.
  *
  * All symbols have a pointer to its next and previous symbol. So it is possible
  * for a Symbol to change its apearance according to the pitch of the surrounding
  * Symbols. This is for example useful for Embellishments, so they can show some
  * kind of message, when they can't be played with this melodynote following them.
  *
  * @attention This class is derived from QGraphicsWidget. So all derived classes from
  * Symbol can be instantiated without reimplementing the virtual functions of QGraphicsItem.
  * This is useful for the non-visible control-items.
  *
  * @todo This class has a Pitch and a NoteLength object, but only MelodyNotes and a few others
  * really need that.
  * Maybe this can be solved by taking the Pitch and NoteLength out of the Symbol and into the Classes that
  * need it and then use the QMetaObject-property system to find out if the symbol has a Pitch respectively NoteLength.
  * Now it is realized, that every class, that inherits from Symbol must reimplement
  * Symbol::hasPitch / Symbol::hasLength.
  */
class Symbol : public QGraphicsWidget
{
public:
    /*! @param scene The GraphicsScene
      * @param pen The pen to draw the symbol
      * @param length A initial length for the symbol
      */
    Symbol( QGraphicsScene *scene, const QPen *pen, NoteLength *length = 0 );

    /*! @brief Every derived class has to reimplement this function.
      * @return True/False, if the derived class has a pitch. False is returned as default.
      */
    virtual bool hasPitch() const;

    /*! @brief Every derived class has to reimplement this function.
      * @return True/False, if the derived class has a length. False is returned as default.
      */
    virtual bool hasLength() const;

    virtual void setPitch( const Pitch* pitch );
    virtual void setLength( NoteLength *length );
    void setNextSymbol( const Symbol *symbol );
    void setPrevSymbol( const Symbol *symbol );

    const Pitch *pitch() const;
    const NoteLength *length() const;

private:
    /*! Pointer to the next Symbol */
    const Symbol *m_nextSymbol;

    /*! Pointer to the previous Symbol */
    const Symbol *m_prevSymbol;


protected:
    /*! The Pitch of the Symbol. */
    const Pitch *m_pitch;

    /*! The NoteLength of the Symbol. */
    NoteLength *m_length;

    /*! The GraphicsScene */
    QGraphicsScene *m_scene;

    /*! The QPen to draw the symbol */
    const QPen *m_pen;
};

#endif // SYMBOL_H
