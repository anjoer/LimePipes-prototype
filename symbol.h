#ifndef SYMBOL_H
#define SYMBOL_H

#include <QGraphicsObject>

class Pitch;

class Symbol : public QGraphicsObject
{
public:
    Symbol();

    enum Length{ NoLength, Whole, Half, Quarter, Eighth, Sixteenth, Thirtysecond };

    void setNextSymbol( const Symbol *symbol );
    void setPrevSymbol( const Symbol *symbol );
    virtual void setLength( Length length );

private:
    const Pitch *m_pitch;
    const Symbol *m_nextSymbol;
    const Symbol *m_prevSymbol;

protected:
    Length m_length;

};

#endif // SYMBOL_H
