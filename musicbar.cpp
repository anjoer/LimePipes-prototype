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

    qreal barHeight = 4*m_pitchList->lineHeight();
    setMinimumSize(360, barHeight);
    setMaximumSize(360, barHeight);
    m_rect = geometry();

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
    /*
    if(contentsWidth()+symbol->geometry().width() > geometry().width())
        return;
    */
    symbol->setParentLayoutItem(this);
    m_layout->addItem( symbol );
    symbol->setVisible(true);
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

void MusicBar::setGeometry(const QRectF &rect)
{
    QGraphicsWidget::setGeometry(rect);
    qDebug() << "New geometry: " << rect;
    m_rect.setWidth(rect.width());
    m_rect.setHeight(rect.height());
}

qreal MusicBar::contentsWidth() const
{
    qreal contentWidth = 0.0;
    for( int i = 0; i<m_layout->count(); i++ ){
        contentWidth += m_layout->itemAt(i)->geometry().width();
    }
    return contentWidth;
}
/*
QSizePolicy MusicBar::sizePolicy() const
{
    return QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}
*/
