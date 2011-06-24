#ifndef MELODYNOTE_H
#define MELODYNOTE_H

#include "melodysymbol.h"
#include "itemtypes.h"

class QGraphicsScene;

class MelodyNote : public MelodySymbol
{
public:
    MelodyNote( const QRectF &rect_, QGraphicsScene *scene );

    enum { Type = MelodyNoteType };
    int type() const { return Type; }
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    QRectF m_rect;
    double m_shear;
    double m_angle;
};

#include <QGraphicsItem>



class EllipseItem : public QObject, public QGraphicsItem
{
public:

    EllipseItem( const QRectF &rect_, QGraphicsScene *scene );




};
#endif // MELODYNOTE_H
