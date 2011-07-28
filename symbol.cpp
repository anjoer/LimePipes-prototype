#include "symbol.h"
#include "pitch.h"
#include "notelength.h"

Symbol::Symbol( QGraphicsScene *scene, const QPen *pen, NoteLength *length )
    :QGraphicsWidget(), m_pitch(0), m_pen(pen)
{
    setVisible(false);
    m_scene = scene;
    m_length = length;
}

bool Symbol::hasPitch() const
{
    return false;
}

bool Symbol::hasLength() const
{
    return false;
}

void Symbol::setPitch(const Pitch *pitch)
{
    if( this->hasPitch() )
    {
        m_pitch = pitch;
    }
}

const Pitch *Symbol::pitch() const
{
    return m_pitch;
}

void Symbol::setNextSymbol( const Symbol *symbol )
{
    m_nextSymbol = symbol;

}

void Symbol::setPrevSymbol(const Symbol *symbol)
{
    m_prevSymbol = symbol;
}

void Symbol::setLength( NoteLength *length)
{
        m_length = length;
}
