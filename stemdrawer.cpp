#include "stemdrawer.h"
#include "symbol.h"
#include <QtGui>
#include <QDebug>


StemDrawer::StemDrawer(QGraphicsScene *scene, const QList<Symbol *> *symbolList, const QPen *pen)
{
    m_symbolList = symbolList;
    if( pen == 0)
    {
        m_pen = new QPen();
    } else {
        m_pen = pen;
    }
    m_rect = QRectF();
    setVisible(true);
}


