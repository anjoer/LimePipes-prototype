#include "musicbar.h"
#include <QtGui>


MusicBar::MusicBar( QGraphicsScene *scene )
    : QGraphicsObject()
{
    m_penwidth = 1;
    m_lineHeight = 15;
    m_rect = QRectF( 0, 0, 4.5*4*m_lineHeight, 4*m_lineHeight ); //Erste Zahl bei Drittem Wert gibt Verhältnis von Breite zur Höhe an

    scene->addItem(this);
}

void MusicBar::paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget )
{
    QPen pen;

#ifdef QT_DEBUG
    painter->setBrush( Qt::transparent );
    painter->setPen( QPen(Qt::red, 1.0) );

    /*Stört hier nur
    //bounding Rect
    painter->drawRect( boundingRect() );

    //Koordinatensystem
    painter->drawLine(0, -20, 0, 20);
    painter->drawLine(-20, 0, 20, 0);
    */
#endif

    //Bar
    pen = QPen(Qt::black, m_penwidth );
    painter->setBrush( Qt::transparent );
    painter->setPen( pen );
    painter->setRenderHint( QPainter::Antialiasing, false );
    painter->drawRect( m_rect );
    for( int i = 1; i<=3; i++ ) {
        painter->drawLine(0, i * m_lineHeight, m_rect.width(), i * m_lineHeight );
    }
}

QRectF MusicBar::boundingRect() const
{
    const double hpw = m_penwidth/2;
    return m_rect.adjusted( -hpw, -hpw, hpw, hpw );
}




