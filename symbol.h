#ifndef SYMBOL_H
#define SYMBOL_H

#include <QGraphicsWidget>
#include "notelength.h"

class Pitch;
class NoteLength;

class Symbol : public QGraphicsWidget
{
public:
    Symbol( QGraphicsScene *scene, const QPen *pen, NoteLength *length = 0 );

    void setNextSymbol( const Symbol *symbol );
    void setPrevSymbol( const Symbol *symbol );
    virtual void setLength( NoteLength *length );
    virtual bool hasPitch() const;
    virtual bool hasLength() const;
    virtual void setPitch( const Pitch* pitch );
    const Pitch *pitch() const;

private:
    const Symbol *m_nextSymbol;
    const Symbol *m_prevSymbol;


protected:
    NoteLength *m_length;
    QGraphicsScene *m_scene;
    const Pitch *m_pitch;
    const QPen *m_pen;
};

#endif // SYMBOL_H
