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
#ifndef STANDARDSTEMDRAWER_H
#define STANDARDSTEMDRAWER_H

#include "stemdrawer.h"
#include "itemtypes.h"

class Symbol;
class NoteLength;
/*! @class StandardStemDrawer
  * @brief The StandardStemDrawer draws the stem for every single MelodyNote. It doesn't
  * tie the melodynotes together.
  */
class StandardStemDrawer : public StemDrawer
{
public:
    /*! @brief Constructor
      * @param scene The GraphicsScene
      * @param symbolList A pointer to the list of symbols
      * @param pen The QPen to draw the Stems
      */
    StandardStemDrawer(QGraphicsScene *scene, const QList<Symbol *> *symbolList, const QPen *pen = 0);
    //! Custom Item Typ itemtypes.h
    enum { Type = StandardStemDrawerType };
    //! Reimplemented from QGraphicsItem
    int type() const { return Type; }
    //! Reimplemented from QGraphicsItem
    QRectF boundingRect() const;
    //! Reimplemented from QGraphicsItem
    void paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget );

public slots:
    //! Update all Stems
    void updateStems();

private:
    /*! @brief Draw a Stem for the given length from a given point .
      * @param painter The QPainter to paint the stems on
      * @param point The connection point of the MelodyNote, where the Stem should start
      * @param length The length of the MelodyNote indicates how the stem looks like.
      */
    void drawStem( QPainter *painter, const QPointF &point, const NoteLength *length );
};

#endif // STANDARDSTEMDRAWER_H
