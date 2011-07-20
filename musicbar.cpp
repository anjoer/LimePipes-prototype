#include "musicbar.h"
#include <QtGui>

#include "pitchlist.h"


MusicBar::MusicBar( QGraphicsScene *scene, const PitchList *pitchList, const QPen *pen)
    : QGraphicsObject()
{
    m_pitchList = pitchList;
    if( pen == 0)
    {
        m_pen = new QPen();
    } else {
        m_pen = pen;
    }
    m_rect = QRectF( 0, 0, 4.5*4*m_pitchList->lineHeight(), 4*m_pitchList->lineHeight() ); //Erste Zahl bei Drittem Wert gibt Verhältnis von Breite zur Höhe an

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
    pen = QPen(Qt::black, m_pen->widthF() );
    painter->setBrush( Qt::transparent );
    painter->setPen( pen );
    painter->setRenderHint( QPainter::Antialiasing, false );
    painter->drawRect( m_rect );
    for( int i = 1; i<=3; i++ ) {
        painter->drawLine(0, i * m_pitchList->lineHeight(), m_rect.width(), i * m_pitchList->lineHeight() );
    }
}

QRectF MusicBar::boundingRect() const
{
    const double hpw = m_pen->widthF()/2;
    return m_rect.adjusted( -hpw, -hpw, hpw, hpw );
}

void MusicBar::setPen(const QPen *pen)
{
    m_pen = pen;
}



