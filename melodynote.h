#ifndef MELODYNOTE_H
#define MELODYNOTE_H

#include "melodysymbol.h"
#include "itemtypes.h"

class QGraphicsScene;

class MelodyNote : public MelodySymbol
{
public:
    MelodyNote( const QRectF &rect_, QGraphicsScene *scene ); //Nur für Testzwecke
    MelodyNote(QGraphicsScene *scene, const Pitch *pitch);

    enum { Type = MelodyNoteType };
    int type() const { return Type; }
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setLength(Length length);

    //Redefined from Symbol
    bool hasPitch() const
    {
        return true;
    }

private:
    QRectF m_rect;
    double m_shear;
    double m_angle;
};

#endif // MELODYNOTE_H
