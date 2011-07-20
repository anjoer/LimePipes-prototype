#include "melodynote.h"
#include "melodysymbol.h"
#include "symbol.h"
#include "pitch.h"
#include <QGraphicsScene>
#include <QtGui>

MelodyNote::MelodyNote( const QRectF &rect_, QGraphicsScene *scene )
    : MelodySymbol(scene),
    m_shear(0.0), m_angle(0.0)
{
    setFlags( QGraphicsItem::ItemIsFocusable |
              QGraphicsItem::ItemIsMovable |
              QGraphicsItem::ItemIsSelectable );
    m_rect = rect_;
    m_rect.moveCenter( QPoint(0.0, 0.0) );
    setPos( rect_.center() );
    scene->clearSelection();
    scene->addItem(this);
    setSelected(true);
    setFocus();
}

MelodyNote::MelodyNote(QGraphicsScene *scene, const Pitch *pitch)
    :MelodySymbol(scene), m_shear(0.0), m_angle(0.0)
{
    m_pitch = pitch;
    setFlags( QGraphicsItem::ItemIsFocusable |
              QGraphicsItem::ItemIsMovable |
              QGraphicsItem::ItemIsSelectable );
    m_rect = QRectF(20, 30, 40, 15);
    m_rect.moveCenter( QPoint(0.0, 0.0) );
    setVisible(true);
    setPos(50, m_pitch->getY());
    scene->clearSelection();
    scene->addItem(this);
    setSelected(true);
    setFocus();
}



void MelodyNote::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen;
#ifdef QT_DEBUG
    painter->setBrush( Qt::transparent );
    painter->setPen( QPen(Qt::gray, 1.0) );

    /* Stört nur
    //bounding Rect
    painter->drawRect( boundingRect() );

    //Shape
    painter->setPen( QPen(Qt::green, 1.0) );
    painter->drawPath( shape() );
    */
#endif

    //Note
    QRectF head = QRectF(0, 0, 30.0, 14.0);
    head.moveCenter( QPointF(0.0, 0.0) );
    if( isSelected() ){
        pen = QPen(Qt::red, 2.5*1.3);
        painter->setBrush( Qt::red );
    } else {
        pen = QPen(Qt::black, 2.5*1.3);
        painter->setBrush( Qt::black );
    }
    painter->setPen( pen );
    painter->rotate( -25.0 );
    painter->shear( 1.0, 0.0 );
    painter->drawEllipse( head );
    painter->shear( -1.0, 0.0 );
    painter->translate( 30.0 /2 , 0 );
    painter->rotate( 25 );
    painter->setPen( pen );
    painter->drawLine( 3, 0, 3, -40.0 );
}

void MelodyNote::setLength(Length length)
{
    if( length != Symbol::NoLength )
    {
        m_length = length;
    }
}

QRectF MelodyNote::boundingRect() const
{
    const double hpw = 2.5;
    return m_rect.adjusted( -hpw, -50, hpw, hpw );
}

QPainterPath MelodyNote::shape() const
{
    QPainterPath path;
    QRectF head = QRectF(0, 0, 30.0, 11.0);
    head.moveCenter( QPointF(0.0, 0.0) );
    path.addRoundedRect( -20, -8.0, 40.0, 16.0, 10.0, 10.0 );
    path.addRect( 15.0, -50.0, 3.5, 50 );
    return path;
}
