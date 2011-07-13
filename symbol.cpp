#include "symbol.h"
#include "pitch.h"

Symbol::Symbol()
{
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
