#ifndef MUSICBAR_H
#define MUSICBAR_H

#include <QGraphicsObject>
#include "itemtypes.h"

class PitchList;

class MusicBar : public QGraphicsObject
{
public:
    MusicBar( QGraphicsScene *scene, const PitchList *pitchList, const QPen *pen = 0);
    enum { Type = MusicBarType };
    int type() const { return Type; }
    QRectF boundingRect() const;
    void paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget );

    void setPen( const QPen *pen );


private:
    const PitchList *m_pitchList;
    QRectF m_rect; //Bounding rectangle
    const QPen *m_pen;
};

#endif // MUSICBAR_H
