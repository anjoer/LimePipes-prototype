#include "musicbar.h"
#include <QtGui>
#include <QDebug>

#include "pitchlist.h"
#include "symbol.h"
#include "pitch.h"


MusicBar::MusicBar( QGraphicsScene *scene, const PitchList *pitchList, const QPen *pen)
    : QGraphicsWidget()
{
    m_pitchList = pitchList;

    m_rect = QRectF( 0, 0, 4.5*4*m_pitchList->lineHeight(), 4*m_pitchList->lineHeight() ); //Erste Zahl bei Drittem Wert gibt Verhältnis von Breite zur Höhe an
    setMinimumSize(360, m_rect.height());
    setPreferredSize(360, m_rect.height());
    setMaximumSize( 800, m_rect.height());

    if( pen == 0)
    {
        m_pen = new QPen();
    } else {
        m_pen = pen;
    }

    m_layout = new QGraphicsLinearLayout;
    m_layout->setSpacing(0.0);
    m_layout->setContentsMargins(0.0, 0.0, 0.0, 0.0 );
    setLayout(m_layout);

    scene->addItem(this);
}

void MusicBar::paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget )
{
    syncGeometryAndRect();
    QPen pen;

#ifdef QT_DEBUG
    painter->setBrush( Qt::transparent );

    /*
    //bounding Rect
    painter->setPen( QPen(Qt::darkBlue, 1.0) );
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
        painter->drawLine(m_rect.left(), m_rect.top() + i * m_pitchList->lineHeight(),
                          m_rect.right(), m_rect.top() + i * m_pitchList->lineHeight() );
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

void MusicBar::append( Symbol *symbol)
{
    symbol->setParentItem(this);
    m_layout->addItem( symbol );
    symbol->setVisible(true);
    //update(m_rect);
}

void MusicBar::append(QList<Symbol *>symbols)
{
    QList<Symbol *>::const_iterator i;
    for( i = symbols.begin(); i != symbols.end(); i++ )
    {
        (*i)->setParentItem(this);
        m_layout->addItem(*i);
    }
}

void MusicBar::prepend(Symbol *symbol)
{
    symbol->setParentItem(this);
    m_symbols.prepend(symbol);
}

void MusicBar::prepend(QList<Symbol *>symbols)
{
    QList<Symbol *>::const_iterator i;
    for( i = symbols.end(); i != symbols.begin(); i-- )
    {
        (*i)->setParentItem(this);
        m_symbols.prepend( *i );
    }
}

QSizePolicy MusicBar::sizePolicy() const
{
    return QSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
}

QRectF MusicBar::contentsRect() const
{
    QRectF t_rect = QRectF(m_rect);
    t_rect.moveTo(mapFromParent(0.0, 0.0));
    return t_rect;
}

void MusicBar::syncGeometryAndRect()
{
    m_rect.setWidth( geometry().width() );
}

