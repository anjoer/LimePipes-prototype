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
#include "melodynote.h"
#include "melodysymbol.h"
#include "symbol.h"
#include "pitch.h"
#include <QGraphicsScene>
#include <QtGui>
#include <QDebug>

MelodyNote::MelodyNote(QGraphicsScene *scene, const QPen *pen, const Pitch *pitch, const NoteLength::Length length)
    :MelodySymbol(scene, pen)
{
    m_rect = QRectF(0.0, 0.0, 1.25*pitch->lineHeight(), pitch->lineHeight());
    m_pitch = pitch;
    m_length = new NoteLength(length);
    setRectForPitch();
    setSizeHintsForPitch();

    setFlags( QGraphicsItem::ItemIsFocusable |
              QGraphicsItem::ItemIsSelectable );
}

bool MelodyNote::hasLineThroughHead(const Pitch *pitch) const
{
    if(pitch->name() == QString("High A")){
        return true;
    }
    return false;
}

void MelodyNote::setPitch(const Pitch *pitch)
{
    if(m_pitch->y() != pitch->y()){
        m_pitch = pitch;
        emit pitchHasChanged();
    }

    setRectForPitch();
    setSizeHintsForPitch();
    setConnectionPoints();
}

void MelodyNote::setRectForPitch()
{
    qreal t_lineHeight = m_pitch->lineHeight();
    qreal t_ypos = m_pitch->y();
    //Set Pitch and update bounding Rect
    m_rect = QRectF(m_rect.left(),
                    mapFromParent(0.0,0.0).y()+ t_ypos - t_lineHeight/2,
                    1.25*t_lineHeight,
                    t_lineHeight );
}

void MelodyNote::setSizeHintsForPitch()
{
    qreal width = m_rect.width();
    qreal height = m_rect.height();
    if(hasLineThroughHead(m_pitch))
    {
        width += 0.4*m_pitch->lineHeight();
    }

    /*! Add 0.15 percentage more space to every sizeHint because they are
      * taller because of the shear
      */
    setMinimumSize(width*1.15, height);
    setPreferredSize(width*1.15, height);
    setMaximumSize(width*1.15, height);
}

void MelodyNote::setConnectionPoints()
{
    QRectF t_rect = mapFromParent(geometry()).boundingRect();
    //Values of the connections
    qreal left_offset = 0.0; //Line through head
    if(hasLineThroughHead(m_pitch)){  //Line through head => notehead a bit more to the right
        left_offset += 0.2*m_rect.width();
    }
    m_leftConnection = mapToParent( QPointF(left_offset + t_rect.left(), m_pitch->y() + 0.25 * m_pitch->lineHeight()) );
}

void MelodyNote::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    setRectForPitch();
#ifdef QT_DEBUG
/*
    //bounding Rect
    painter->setPen( QPen(Qt::blue, 1.0) );
    painter->setBrush( Qt::transparent );
    painter->drawRect( boundingRect() );

    //geometry Rect
    painter->setPen( QPen(Qt::darkMagenta, 1.0) );
    painter->setBrush( Qt::transparent );
    painter->drawPolygon( mapFromParent(geometry()) );

    //Shape
    painter->setPen( QPen(Qt::green, 1.0) );
    painter->drawPath( shape() );


    //koordinatensystem
    painter->setPen(QPen(Qt::green, 1.0));
    painter->drawLine(-20, 0, 20, 0);
    painter->drawLine(0, -20, 0, 20);
    painter->setPen(Qt::NoPen);
    //ende koordinatensystem
*/
#endif

    //Notehead
    painter->setPen( Qt::NoPen );
    painter->setBrush( Qt::SolidPattern );
    painter->translate(m_rect.left()+m_rect.width()/2 + 1.0, //y-value + offset, so that notehad don't overlaps the y-axis
                   m_rect.center().y() + 0.5);
    
    QRectF headrect = QRectF(0.0, 0.0, m_rect.width(), m_pitch->lineHeight());
    qreal xShiftForLine = 0.0;
    if( hasLineThroughHead(m_pitch) ){ //Line through head => notehead a bit more to the right
        xShiftForLine = 0.2*m_rect.width();
    }
    headrect.moveCenter( QPoint( xShiftForLine, 0.0 ));

    QPainterPath noteHead;
    noteHead.addEllipse(headrect);
    if(m_length->length() == NoteLength::Whole || m_length->length() == NoteLength::Half ){
        qreal lineHeight = m_pitch->lineHeight();
        QPainterPath holeInHead;
        holeInHead.addEllipse(headrect.adjusted(lineHeight*0.25, lineHeight*0.3, -lineHeight*0.25, -lineHeight*0.3));
        noteHead -= holeInHead;
    }

    painter->save();
    painter->rotate( -4.0 );
    painter->shear( -0.6, -0.0 );
    painter->drawPath(noteHead);
    painter->restore();

    if( hasLineThroughHead(m_pitch) ) //High A => draw line through notehead
    {
        painter->setRenderHint( QPainter::Antialiasing, false );
        painter->setPen(QPen(Qt::black, 2.0));
        painter->drawLine(-m_rect.width()/2, 0.0, m_rect.width()/2+0.4*m_rect.width(), 0.0 );
    }
}

void MelodyNote::setLength(NoteLength *length)
{
    if(m_length->length() != length->length()){
        m_length = length;
        emit lengthHasChanged();
    }
}

QRectF MelodyNote::boundingRect() const
{
    qreal hpw = m_pen->width() / 2;
    qreal right = 0.0;
    if( hasLineThroughHead(m_pitch) ) {
        right += 0.4*m_rect.width();
    }
    return m_rect.adjusted( -hpw, -hpw, right, hpw ); //Notehead is drawn without pen,
                                                      //but notehead has space on the topside and bottomside because of the barlines => increase bounding rect
}

QPainterPath MelodyNote::shape() const
{
    QPainterPath path;
    path.addRect(m_rect);
    return path;
}

void MelodyNote::mousePressEvent( QGraphicsSceneMouseEvent *event )
{
    m_dragStartY = event->pos().y();
    m_dragStartX = event->pos().x();
    //qDebug() << "MelodyNote - Length: " << m_length->length();
    //qDebug() << "MelodyNote - Pitch: " << m_pitch->name();
    QGraphicsItem::mousePressEvent( event );
}

void MelodyNote::mouseReleaseEvent( QGraphicsSceneMouseEvent *event )
{
    QGraphicsItem::mouseReleaseEvent( event );
}

void MelodyNote::mouseMoveEvent( QGraphicsSceneMouseEvent *event )
{
    qreal yPos = event->pos().y();
    qreal ydist = m_dragStartY - yPos;
    qreal nextPitchDist = m_pitch->lineHeight() / 2;

    qreal xPos = event->pos().x();
    qreal xdist = m_dragStartX - xPos;
    qreal nextLengthDist = m_pitch->lineHeight(); //ratio for changing pitch is the same for changing notelength

    //up and down -- Pitch
    if( ydist > 0 ) //up
    {
        if( ydist > (nextPitchDist/2) ){
            if(m_pitch->nextHigher() != 0){
                m_dragStartY -= nextPitchDist;
                prepareGeometryChange();
                setPitch( m_pitch->nextHigher() );
                emit pitchHasChanged();
                //qDebug() << "MelodyNote - New Pitch: " << m_pitch->name();
            }
        }
    } else if( ydist < 0 ) { //down
        if( -ydist > (nextPitchDist/2) ){
            if(m_pitch->nextLower() != 0){
                m_dragStartY += nextPitchDist;
                prepareGeometryChange();
                setPitch( m_pitch->nextLower() );
                emit pitchHasChanged();
                //qDebug() << "MelodyNote - New Pitch: " << m_pitch->name();
            }
        }
    }

    //left and right -- Length
    if( xdist > 0 ) //left
    {
        if( xdist > (nextLengthDist) ){
            if( m_length->length() != NoteLength::Thirtysecond ){
                m_dragStartX -= nextLengthDist;
            }
            (*m_length)--;
            emit lengthHasChanged();
            //qDebug() << "MelodyNote - New Length: " << m_length->length();
            update();
        }
    } else if( xdist < 0 ) { //right
        if( -xdist > (nextLengthDist) ){
            if( m_length->length() != NoteLength::Whole ){
                m_dragStartX += nextLengthDist;
            }
            (*m_length)++;
            emit lengthHasChanged();
            //qDebug() << "MelodyNote - New Length: " << m_length->length();
            update();
        }
    }

    QGraphicsItem::mouseMoveEvent( event );
}

QSizePolicy MelodyNote::sizePolicy() const
{
    return QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

QPointF MelodyNote::leftConnection() const
{
    return m_leftConnection;
}


QPointF MelodyNote::rightConnection() const
{
    return m_rightConnection;
}


void MelodyNote::setGeometry(const QRectF &rect)
{
    QGraphicsWidget::setGeometry(rect);
    QPointF t_leftConnection = m_leftConnection;
    setConnectionPoints();
    if(t_leftConnection != m_leftConnection){
        emit pitchHasChanged();
    }
}
