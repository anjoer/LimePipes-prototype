#ifndef MELODYNOTE_H
#define MELODYNOTE_H

#include "melodysymbol.h"
#include "itemtypes.h"

class QGraphicsScene;

class MelodyNote : public MelodySymbol
{
public:
    MelodyNote(QGraphicsScene *scene, const QPen *pen, const Pitch *pitch);

    enum { Type = MelodyNoteType };
    int type() const { return Type; }
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void setPitch(const Pitch *pitch); //Redefine from Symbol
    void paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setLength(Length length);
    QSizePolicy sizePolicy() const;

    //Redefined from Symbol
    bool hasPitch() const
    {
        return true;
    }

private:
    QRectF m_rect;  //Bounding Rect
    QPointF m_leftConnection;
    QPointF m_rightConnection;
    qreal m_dragStartY;
    bool hasLineThroughHead(const Pitch *pitch ) const;
    void setRectForPitch();
    void setSizeHintsForPitch();

protected:
    void mousePressEvent( QGraphicsSceneMouseEvent *event );
    void mouseReleaseEvent( QGraphicsSceneMouseEvent *event );
    void mouseMoveEvent( QGraphicsSceneMouseEvent *event );
};

#endif // MELODYNOTE_H
