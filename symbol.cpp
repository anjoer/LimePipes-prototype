#include "symbol.h"
#include "pitch.h"

Symbol::Symbol( QGraphicsScene *scene )
    :QGraphicsObject(), m_pitch(0)
{
    setVisible(false);
    m_scene = scene;
}

bool Symbol::hasPitch() const
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

void Symbol::setNextSymbol( const Symbol *symbol )
{
    m_nextSymbol = symbol;

}

void Symbol::setPrevSymbol(const Symbol *symbol)
{
    m_prevSymbol = symbol;
}

void Symbol::setLength(Length length)
{
    if( m_length != NoLength )
    {
        m_length = length;
    }

}
