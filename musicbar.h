#ifndef MUSICBAR_H
#define MUSICBAR_H

#include <QGraphicsObject>
#include "itemtypes.h"

class MusicBar : public QGraphicsObject
{
public:
    MusicBar( QGraphicsScene *scene );
    enum { Type = MusicBarType };
    int type() const { return Type; }
    QRectF boundingRect() const;
    void paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget );

private:
    QRectF m_rect;
    double m_penwidth;
    double m_lineheight;
};

#endif // MUSICBAR_H
