#ifndef GHBTUNE_H
#define GHBTUNE_H

#include <QList>
#include <QVector>

class QGraphicsScene;

class PitchList;
class MusicBar;
class Symbol;


class GHBTune
{
public:
    GHBTune( QGraphicsScene *scene );
    ~GHBTune();

private:
    QList<Symbol *> m_symbols;
    QVector<MusicBar *> m_bars;
    const PitchList *m_pitchList;
};

#endif // GHBTUNE_H
