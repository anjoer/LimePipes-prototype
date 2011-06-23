#ifndef MUSICBAR_H
#define MUSICBAR_H

#include <QGraphicsObject>

class MusicBar : public QGraphicsObject
{
public:
    MusicBar( QGraphicsScene *scene );
    enum { Type = QGraphicsItem::UserType + 2 };
    int type() const { return Type; }
    QRectF boundingRect() const;
    void paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget );

private:
    QRectF m_rect;
    double m_penwidth;
    double m_lineheight;
};

#endif // MUSICBAR_H
