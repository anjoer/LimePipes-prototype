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
#ifndef STEMDRAWER_H
#define STEMDRAWER_H

#include <QGraphicsWidget>
#include "itemtypes.h"

class Symbol;

/*! @class StemDrawer
  * @brief This is the baseclass for all StemDrawers.
  *
  * StemDrawer draw the stems for the melodynotes, according to their length. Possible Stemdrawers are:
  * <dl>
  *  <dt>Standard Stem Drawer</dt>
  *  <dd>Draws a Stem on every MelodyNote but don't ties the stems together.
  *  @image html standard_stemdrawer.png "Standard StemDrawer-example made in BagpipePlayer"
  *  <dt>6/8 Stem Drawer</dt>
  *  <dd>Draws Stems to the MelodyNotes and ties them together like in a common 6/8 March
  *  with two groupings (beats) in a bar.
  *  @image html 68_stemdrawer.png "6/8 StemDrawer-example made in BagpipePlayer"
  * </dl>
  */
class StemDrawer : public QGraphicsWidget
{
    Q_OBJECT

public:
    /*! @brief Constructor
      * @param scene The GraphicsScene
      * @param symbolList A Pointer to the list of symbols
      * @param pen The pen to draw the stems
      * @todo Compiler says, that scene is an unused parameter. Reconsider if we use that.
      */
    StemDrawer(QGraphicsScene *scene, const QList<Symbol *> *symbolList, const QPen *pen = 0);

    //! Custom Item Typ itemtypes.h
    enum { Type = StemDrawerType };

    //! Reimplemented from QGraphicsItem
    int type() const { return Type; }

protected:
    //! The pointer to the list of symbols
    const QList<Symbol *> *m_symbolList;

    //! The bounding rect
    QRectF m_rect;

    //! The pen to draw the stems
    const QPen *m_pen;

public slots:
    //! update all stems
    virtual void updateStems() = 0;
};

#endif // STEMDRAWER_H
