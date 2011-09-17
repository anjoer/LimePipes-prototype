#ifndef STANDARDSTEMDRAWER_H
#define STANDARDSTEMDRAWER_H

#include "stemdrawer.h"
#include "itemtypes.h"

class Symbol;
class NoteLength;

class StandardStemDrawer : public StemDrawer
{
public:
    StandardStemDrawer(QGraphicsScene *scene, const QList<Symbol *> *symbolList, const QPen *pen = 0);
    enum { Type = StandardStemDrawerType };
    int type() const { return Type; }
    QRectF boundingRect() const;
    void paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget );

public slots:
    void updateStems();

private:

    void drawStem( QPainter *painter, const QPointF &point, const NoteLength *length );
};

#endif // STANDARDSTEMDRAWER_H
