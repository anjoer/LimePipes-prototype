#ifndef MELODYNOTE_H
#define MELODYNOTE_H

#include "melodysymbol.h"
#include "itemtypes.h"

class QGraphicsScene;

class MelodyNote : public MelodySymbol
{
    Q_OBJECT
public:
    MelodyNote(QGraphicsScene *scene, const QPen *pen, const Pitch *pitch, const NoteLength::Length length = NoteLength::Quarter);

    enum { Type = MelodyNoteType };
    int type() const { return Type; }
    QRectF boundingRect() const;
    QPainterPath shape() const;
    QSizePolicy sizePolicy() const;
    void paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setGeometry(const QRectF &rect);


    void setPitch(const Pitch *pitch); //Redefine from Symbol
    void setLength(NoteLength *length);
    QPointF leftConnection() const;
    QPointF rightConnection() const;



    //Redefined from Symbol
    bool hasPitch() const
    {
        return true;
    }
    bool hasLength() const
    {
        return true;
    }

private:
    QRectF m_rect;  //Bounding Rect
    QPointF m_leftConnection;
    QPointF m_rightConnection;
    qreal m_dragStartY;
    qreal m_dragStartX;
    bool hasLineThroughHead(const Pitch *pitch ) const;
    void setRectForPitch();
    void setSizeHintsForPitch();
    void setConnectionPoints();

protected:
    void mousePressEvent( QGraphicsSceneMouseEvent *event );
    void mouseReleaseEvent( QGraphicsSceneMouseEvent *event );
    void mouseMoveEvent( QGraphicsSceneMouseEvent *event );

signals:
    void pitchHasChanged();
    void lengthHasChanged();
};

#endif // MELODYNOTE_H
