#include "melodynote.h"
#include "melodysymbol.h"
#include "symbol.h"
#include "pitch.h"
#include <QGraphicsScene>
#include <QtGui>
#include <QDebug>

/************************************************************************************
  * Für die Note zählt die obere linke Ecke von ihrer Geometry als 0,0. D.h. das ParentItem (MusicBar)
  * muss dafür sorgen, dass diese Koordinate nicht durch das Layout versetzt wurde (contentsMargins).
  * Somit ist das Geometry-Rechteck immer in der letzten, oberen Zeile der MusicBar. Die Note kümmert sich
  * selber darum, wie/wo sie gezeichnet wird, z.B. beim Wechsel des Pitch durch Drag mit der Maus.
  * Somit zeichnet sich die Note auch auserhalb der Geometry
  *
  *
  *
  *********************************************************************************/

MelodyNote::MelodyNote(QGraphicsScene *scene, const QPen *pen, const Pitch *pitch, const NoteLength::Length length)
    :MelodySymbol(scene, pen)
{
    m_rect = QRectF(0.0, 0.0, 1.25*pitch->lineHeight(), pitch->lineHeight());
    m_pitch = pitch;
    m_length = new NoteLength(length);
    setRectForPitch();
    setSizeHintsForPitch();

    qreal t_lineHeight = m_pitch->lineHeight();
    qreal t_ypos = m_pitch->y();

    setFlags( QGraphicsItem::ItemIsFocusable |
              QGraphicsItem::ItemIsSelectable );


    //Werte der Connections
    m_leftConnection = mapToScene( QPointF(0.0 - 0.04*m_pitch->lineHeight(), m_pitch->y() + 0.25 * m_pitch->lineHeight()) );
    m_rightConnection = mapToScene( QPointF(m_rect.width() + 0.05*t_lineHeight, t_ypos - 0.25 * t_lineHeight) );

    scene->addItem(this);
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
    m_pitch = pitch;
    setRectForPitch();
    setSizeHintsForPitch();
}

void MelodyNote::setRectForPitch()
{
    qreal t_lineHeight = m_pitch->lineHeight();
    qreal t_ypos = m_pitch->y();
    //Set Pitch and update bounding Rect
    //m_rect = QRectF(m_rect.left(), t_ypos - t_lineHeight/2 , 1.25*t_lineHeight, t_lineHeight ); //Breite des Notenkopfes = offset mal Zeilenhöhe
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
    setMinimumSize(width*1.15, height); // jeweils 0.1 mehr, da noten etwas größer sind durch die scherung
    setPreferredSize(width*1.15, height);
    setMaximumSize(width*1.15, height);
}

void MelodyNote::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    setRectForPitch();
#ifdef QT_DEBUG
    /*
    //bounding Rect
    painter->setPen( QPen(Qt::gray, 1.0) );
    painter->setBrush( Qt::transparent );
    painter->drawRect( boundingRect() );
    */
    //Shape
    //painter->setPen( QPen(Qt::green, 1.0) );
    //painter->drawPath( shape() );
#endif
    /*
    //koordinatensystem
    painter->setPen(QPen(Qt::green, 1.0));
    painter->drawLine(-20, 0, 20, 0);
    painter->drawLine(0, -20, 0, 20);
    painter->setPen(Qt::NoPen);
    //ende koordinatensystem
    */
    //Notenkopf
    painter->setPen( Qt::NoPen );
    painter->setBrush( Qt::SolidPattern );

    
    QRectF head = QRectF(0.0, 0.0, m_rect.width(), m_pitch->lineHeight());
    painter->translate(m_rect.left()+m_rect.width()/2 + 1.0, //y-wert + offset, damit Notenkopf nicht links über y-Achse steht
                       m_rect.center().y() + 0.5); //y-Wert + offset, damit Notenkopf genau zwischen Linien steht

    painter->save();
    painter->rotate( -4.0 );
    painter->shear( -0.6, -0.0 );

    qreal xShiftForLine = 0.0;
    if( hasLineThroughHead(m_pitch) ){
        xShiftForLine = 0.2*m_rect.width();
    }
    head.moveCenter( QPoint( xShiftForLine, 0.0 ));

    painter->drawEllipse( head );

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
        m_length = length;
}

QRectF MelodyNote::boundingRect() const
{
    qreal hpw = m_pen->width() / 2;
    qreal left = -hpw *2;
    qreal right = 0.0;
    if( hasLineThroughHead(m_pitch) ) {
        left -= 0.2*m_rect.width();
        right += 0.4*m_rect.width();
    }
    return m_rect.adjusted( -hpw, -hpw, right, hpw ); //Note wird ohne Pen gezeichnet,
                                                       //aber da die Linie der Notenzeile nach oben und unten platz hat, bounding rect vergrößern
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
    qDebug() << "DragStart länge: " << m_length->length();
    //qDebug() << "Start dragging Note. Pitch: " << m_pitch->getName();
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
    qreal nextLengthDist = m_pitch->lineHeight(); //Verhältnis gleich zu Bewegung um Pitch zu ändern

    //up and down -- Pitch
    if( ydist > 0 ) //up
    {
        if( ydist > (nextPitchDist/2) ){
            if(m_pitch->nextHigher() != 0){
                m_dragStartY -= nextPitchDist;
                prepareGeometryChange();
                setPitch( m_pitch->nextHigher() );
            }
        }
    } else if( ydist < 0 ) { //down
        if( -ydist > (nextPitchDist/2) ){
            if(m_pitch->nextLower() != 0){
                m_dragStartY += nextPitchDist;
                prepareGeometryChange();
                setPitch( m_pitch->nextLower() );                
            }
        }
    }

    //left and right -- Length
    if( xdist > 0 ) //left
    {
        //qDebug() << "links, start länge: " << m_length->length();
        if( xdist > (nextLengthDist) ){
            if( m_length->length() != NoteLength::Thirtysecond ){
                m_dragStartX -= nextLengthDist;
            }
            (*m_length)--;
            qDebug() << "neue länge: " << m_length->length();
        }
    } else if( xdist < 0 ) { //right
        //qDebug() << "rechts, start länge: " << m_length->length();
        if( -xdist > (nextLengthDist) ){
            if( m_length->length() != NoteLength::Whole ){
                m_dragStartX += nextLengthDist;
            }
            (*m_length)++;
            qDebug() << "neue länge: " << m_length->length();
        }
    }

    QGraphicsItem::mouseMoveEvent( event );
}

QSizePolicy MelodyNote::sizePolicy() const
{
    return QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}
