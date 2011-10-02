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
#include "musicbar.h"
#include <QtGui>
#include <QDebug>

#include "pitchlist.h"
#include "standardstemdrawer.h"
#include "symbol.h"
#include "pitch.h"
#include "melodynote.h"


MusicBar::MusicBar( QGraphicsScene *scene, const PitchList *pitchList, const QPen *pen)
    : QGraphicsWidget()
{
    m_pitchList = pitchList;
    m_stemDrawer = new StandardStemDrawer(scene, &m_symbols, pen);
    m_stemDrawer->setParentItem(this);

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
    m_layout->setSpacing(3.0); /*! Space between Symbols */
    m_layout->setContentsMargins(3.0, 0.0, 0.0, 0.0 ); /*! Second value must be 0.0, PitchList relys on that */
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
    symbol->setVisible(true);

    m_symbols.append( symbol );
    m_layout->addItem( symbol );

    if(symbol->type() == MelodyNoteType)
    {
        MelodyNote *note = qgraphicsitem_cast<MelodyNote *>(symbol);
        connect(note, SIGNAL(pitchHasChanged()),
                m_stemDrawer, SLOT(updateStems()));
        connect(note, SIGNAL(lengthHasChanged()),
                m_stemDrawer, SLOT(updateStems()));
    }

}

void MusicBar::append(QList<Symbol *>symbols)
{
    QList<Symbol *>::const_iterator i;
    for( i = symbols.begin(); i != symbols.end(); i++ )
    {
        (*i)->setParentItem(this);
        m_layout->addItem(*i);
        parentItem()->update();
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
    m_rect.setWidth(rect.width());
    m_rect.setHeight(rect.height());
}
