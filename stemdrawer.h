#ifndef STEMDRAWER_H
#define STEMDRAWER_H

#include <QGraphicsWidget>
#include "itemtypes.h"

class Symbol;

class StemDrawer : public QGraphicsWidget
{
    Q_OBJECT

public:
    StemDrawer(QGraphicsScene *scene, const QList<Symbol *> *symbolList, const QPen *pen = 0);
    enum { Type = StemDrawerType };
    int type() const { return Type; }

protected:
    const QList<Symbol *> *m_symbolList;
    QRectF m_rect;
    const QPen *m_pen;

public slots:
    virtual void updateStems() = 0;
};

#endif // STEMDRAWER_H
