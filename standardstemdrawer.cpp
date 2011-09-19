#include "standardstemdrawer.h"
#include <QtGui>
#include "symbol.h"
#include "melodynote.h"
#include "notelength.h"
#include <QDebug>


StandardStemDrawer::StandardStemDrawer(QGraphicsScene *scene, const QList<Symbol *> *symbolList, const QPen *pen)
    :StemDrawer(scene, symbolList, pen)
{

}

void StandardStemDrawer::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //qDebug() << "Stemdrawer.paint";
    if(m_rect.isEmpty()){
        m_rect = QRectF(parentItem()->boundingRect().adjusted(0.0, -20.0, 0.0, 50.0));
    }
/*
    //bounding Rect
    painter->setPen( QPen(Qt::darkBlue, 1.0) );
    painter->drawRect( boundingRect() );

    //Koordinatensystem
    painter->drawLine(0, -20, 0, 20);
    painter->drawLine(-20, 0, 20, 0);
*/
    QList<Symbol *>::const_iterator i;
    for( i = m_symbolList->begin(); i<m_symbolList->end(); i++ )
    {
        if( (*i)->type() ==  MelodyNoteType ){
            MelodyNote *note = qgraphicsitem_cast<MelodyNote *>(*i);
            //qDebug() << "StandardStemDrawer-leftconnection: " << note->leftConnection();
            drawStem( painter, note->leftConnection(), note->length() );
        }

    }
}

QRectF StandardStemDrawer::boundingRect() const
{
    const double hpw = m_pen->widthF()/2;
    return m_rect.adjusted( -hpw, -hpw, hpw, hpw );
}

void StandardStemDrawer::drawStem(QPainter *painter, const QPointF &point, const NoteLength *length)
{
   // qDebug() << "StandardStemDrawer::drawStem";
    //ToDo: At this point, lineHeight must be assigned here, hardcoded -> change...
    qreal lineHeight = 14.0;

    painter->setPen( QPen(Qt::black, 1.0));
    QPointF t_pointTop = point;
    t_pointTop += QPoint(m_pen->widthF(), 0.0);
    t_pointTop = mapFromParent(t_pointTop);
    QPointF t_pointBottom = QPoint(t_pointTop.x(), t_pointTop.y()+lineHeight*3.3);

    switch(length->length()){ //
    case NoteLength::Whole:
        break;
    case NoteLength::Half:
    case NoteLength::Quarter:
        painter->drawLine(t_pointTop, t_pointBottom );
        break;
    case NoteLength::Eighth:
        painter->drawLine(t_pointTop, t_pointBottom );
        painter->drawLine(t_pointBottom, t_pointBottom + QPointF(20.0, -15.0));
        break;
    case NoteLength::Sixteenth:
        painter->drawLine(t_pointTop, t_pointBottom );
        painter->drawLine(t_pointBottom, t_pointBottom + QPointF(20.0, -15.0));
        painter->drawLine(t_pointBottom + QPointF(0.0, -10.0), t_pointBottom + QPointF(20.0, -25.0));
        break;
    case NoteLength::Thirtysecond:
        painter->drawLine(t_pointTop, t_pointBottom );
        painter->drawLine(t_pointBottom, t_pointBottom + QPointF(20.0, -15.0));
        painter->drawLine(t_pointBottom + QPointF(0.0, -10.0), t_pointBottom + QPointF(20.0, -25.0));
        painter->drawLine(t_pointBottom + QPointF(0.0, -20.0), t_pointBottom + QPointF(20.0, -35.0));
        break;
    default:
        qDebug() << "StandardStemDrawer::drawStem - Length not covered";
    }
}

void StandardStemDrawer::updateStems()
{
    //qDebug() << "StemDrawer.updateStems: ";
    update(m_rect);
}
