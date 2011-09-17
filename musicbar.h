#ifndef MUSICBAR_H
#define MUSICBAR_H

#include <QGraphicsWidget>
#include <QList>

#include "itemtypes.h"

class PitchList;
class StemDrawer;
class Symbol;
class QGraphicsLinearLayout;

class MusicBar : public QGraphicsWidget
{
    Q_OBJECT
public:
    MusicBar( QGraphicsScene *scene, const PitchList *pitchList, const QPen *pen = 0);
    enum { Type = MusicBarType };
    int type() const { return Type; }
    QRectF boundingRect() const;
    void paint( QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget );
    void setGeometry(const QRectF &rect);

    void setPen( const QPen *pen );
    void append( Symbol *symbol );
    void append( QList<Symbol *>symbols);
    void prepend( Symbol *symbol );
    void prepend( QList<Symbol *>symbols );

    qreal contentsWidth() const;
    //QRectF contentsRect() const;
    //QSizePolicy sizePolicy() const;

private:
    QList<Symbol *>m_symbols;
    const PitchList *m_pitchList;
    StemDrawer *m_stemDrawer;
    QRectF m_rect; //Bounding rectangle
    const QPen *m_pen;
    QGraphicsLinearLayout *m_layout;
};

#endif // MUSICBAR_H
