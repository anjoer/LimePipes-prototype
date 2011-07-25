#ifndef GHBTUNE_H
#define GHBTUNE_H

#include <QList>
#include <QVector>
#include <QGraphicsWidget>

class QGraphicsScene;
class QGraphicsLinearLayout;

class PitchList;
class MusicBar;
class Symbol;


class GHBTune : public QGraphicsWidget
{
public:
    GHBTune( QGraphicsScene *scene );
    ~GHBTune();
    QRectF boundingRect() const;
    QSizePolicy sizePolicy() const;

private:
    QVector<MusicBar *> m_bars;
    const PitchList *m_pitchList;
    QGraphicsLinearLayout *m_layout;
    QRectF m_rect;
    QPen *m_pen;
};

#endif // GHBTUNE_H
