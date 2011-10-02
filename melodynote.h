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
#ifndef MELODYNOTE_H
#define MELODYNOTE_H

#include "melodysymbol.h"
#include "itemtypes.h"

class QGraphicsScene;

/*!
 * @class MelodyNote
 * @brief This class represents melody notehead.
 *
 * It can be draged up and down for increasing/decreasing its pitch. By dragging it
 * left and right, its length can be increased (right) or decreased (left).
 *
 * @section Coordinates
 * For every melody-note, the 0-point of the local coordinate system is the same as the 0-point
 * of its geometry. The geometry's y-0-point must be the same as the parents y-0-point.
 * @image html melodynote_coordinates.png "melody-notes coordinates"
 * The parent item has to take care, that the geometry of the melody note hasn't been shifted by
 * a layout (y-contentsMargins), in which the melody note is eventually in. The melody note takes
 * care itself, where it is drawn, depending on the pitch. So it is mostly drawn outside of the geometry
 * because it uses only the 0-x-coordinate to get the right position in the bar.
 *
 * @section Notelength
 * A melody-note has a length-value. It increases/decreases the value, depending on the direction
 * where it is dragged. It don't care about the right Stem to draw according to the length. This is up
 * to a @ref StemDrawer to draw the right Stems for the note.
 */
class MelodyNote : public MelodySymbol
{
    Q_OBJECT
public:
    /*! @brief Constructor
      * @param scene The GraphicsScene
      * @param pen The pen with wich the note should be drawn
      * @param pitch The initial pitch of the melody note
      * @param length The initial length of the note
      */
    MelodyNote(QGraphicsScene *scene, const QPen *pen, const Pitch *pitch, const NoteLength::Length length = NoteLength::Quarter);

    //! Custom Item Typ itemtypes.h
    enum { Type = MelodyNoteType };

    //! Reimplemented from QGraphicsItem
    int type() const { return Type; }
    //! Reimplemented from QGraphicsItem
    QRectF boundingRect() const;
    //! Reimplemented from QGraphicsItem
    QPainterPath shape() const;
    //! Reimplemented from QGraphicsItem
    void paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    //! Reimplemented from QGraphicsWidget
    QSizePolicy sizePolicy() const;
    //! Reimplemented from QGraphicsLayoutItem
    void setGeometry(const QRectF &rect);

    //! @brief Returns the point of the left connection for the stem
    //! @return The Point in parent coordinates
    QPointF leftConnection() const;
    //! @brief Returns the point of the right connection for the stem
    //! @return The point in parent coordinates
    QPointF rightConnection() const;

    void setPitch(const Pitch *pitch);
    void setLength(NoteLength *length);


    //! Reimplemented from Symbol. Melody notes have a pitch
    bool hasPitch() const
    {
        return true;
    }
    //! Reimplemented from Symbol. Melody notes have a length
    bool hasLength() const
    {
        return true;
    }

private:
    //! The bounding rect
    QRectF m_rect;
    //! The left connection point in parent coordinates
    QPointF m_leftConnection;
    //! The right connection point in parent coordinates
    QPointF m_rightConnection;
    //! Helper variable for mousePressEvent and mouseMoveEvent while dragging the note
    qreal m_dragStartY;
    //! Helper variable for mousePressEvent and mouseMoveEvent while dragging the note
    qreal m_dragStartX;

    /*! @brief Has the given pitch a line through the notehead
      * @return
      * <ul>
      *   <li>true: pitch has line through notehead</li>
      *   <li>false: pitch has no line through notehead</li>
      * </ul>
      */
    bool hasLineThroughHead(const Pitch *pitch ) const;
    //! Sets the bounding rect (m_rect) for the actual pitch (m_pitch).
    void setRectForPitch();
    /*! @brief Set the sizeHints for the actual pitch.
      *
      * Has notehead a line through it, the width is taller.
      */
    void setSizeHintsForPitch();
    /*! @brief Set the connection points for the actual pitch.
      *
      * Has notehead a line through it, the points are shifted a bit more to the right.
      */
    void setConnectionPoints();

protected:
    void mousePressEvent( QGraphicsSceneMouseEvent *event );
    void mouseReleaseEvent( QGraphicsSceneMouseEvent *event );
    void mouseMoveEvent( QGraphicsSceneMouseEvent *event );

signals:
    void pitchHasChanged();
    void lengthHasChanged();
};

#endif // MELODYNOTE_H
