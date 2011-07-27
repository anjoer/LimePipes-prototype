#ifndef MUSICBAR_H
#define MUSICBAR_H

#include <QGraphicsWidget>
#include <QList>

#include "itemtypes.h"

class PitchList;
class Symbol;
class QGraphicsLinearLayout;

class MusicBar : public QGraphicsWidget
{
public:
    MusicBar( QGraphicsScene *scene, const PitchList *pitchList, const QPen *pen = 0);
    enum { Type = MusicBarType };
    int type() const { return Type; }
    QRectF boundingRect() const;
    void paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget );

    void setPen( const QPen *pen );
    void append( Symbol *symbol );
    void append( QList<Symbol *>symbols);
    void prepend( Symbol *symbol );
    void prepend( QList<Symbol *>symbols );
    void setGeometry(const QRectF &rect);
    qreal contentsWidth() const;
    //QRectF contentsRect() const;
    //QSizePolicy sizePolicy() const;

private:
    const PitchList *m_pitchList;
    QList<Symbol *>m_symbols;
    QRectF m_rect; //Bounding rectangle
    const QPen *m_pen;
    QGraphicsLinearLayout *m_layout;
};

#endif // MUSICBAR_H
