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
#ifndef MUSICBAR_H
#define MUSICBAR_H

#include <QGraphicsWidget>
#include <QList>

#include "itemtypes.h"

class PitchList;
class StemDrawer;
class Symbol;
class QGraphicsLinearLayout;

/*!
  * @class MusicBar
  * @brief This class is a standard music-bar.
  * @image html musicbar_coordinates.png "The coordinate-system of a MusicBar"
  *
  * It has a list with symbols. The symbols are arranged by a QGraphicsLinearLayout.
  * Its @ref StemDrawer draws the stems of the melody-notes in the list.
  *
  * @todo Do we need the symbols in the layout and in the list? Reconsider design.
  */
class MusicBar : public QGraphicsWidget
{
    Q_OBJECT
public:
    /*!
      * @brief Constructor
      * @param scene The GraphicsScene
      * @param pitchList The @ref PitchList for the specific instrument (Great Higland Bagpipes for example)
      * @param pen The pen with wich the music-bar is drawn
      */
    MusicBar( QGraphicsScene *scene, const PitchList *pitchList, const QPen *pen = 0);
    //! Custom Item Typ itemtypes.h
    enum { Type = MusicBarType };
    //! Reimplemented from QGraphicsItem
    int type() const { return Type; }
    //! Reimplemented from QGraphicsItem
    QRectF boundingRect() const;
    //! Reimplemented from QGraphicsItem
    void paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget );
    //! Reimplemented from QGraphicsLayoutItem
    void setGeometry(const QRectF &rect);

    //! Set pen for drawing the music-bar
    void setPen( const QPen *pen );

    /*! Append a symbol to the bar
      * @note Only this function for appending Symbols is fully implemented yet.
      */
    void append( Symbol *symbol );

    /*! Append a list of symbols to the bar.
      * @note This function isn't fully implemented yet.
      */
    void append( QList<Symbol *>symbols);

    /*! Prepend a symbol to the bar.
      * @note This function isn't fully implemented yet.
      */
    void prepend( Symbol *symbol );

    /*! Prepend a list of symbols to the bar.
      * @note This function isn't fully implemented yet.
      */
    void prepend( QList<Symbol *>symbols );

private:
    //! @brief The list with the symbols in the bar
    QList<Symbol *>m_symbols;
    //! @brief The @ref PitchList for the specific instrument
    const PitchList *m_pitchList;
    //! @brief The @ref StemDrawer for the bar.
    StemDrawer *m_stemDrawer;
    //! @brief The bounding rectangle
    QRectF m_rect;
    //! @brief The pen for drawing the bar
    const QPen *m_pen;
    //! @brief The layout for the symbols
    QGraphicsLinearLayout *m_layout;
};

#endif // MUSICBAR_H
