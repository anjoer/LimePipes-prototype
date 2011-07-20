#ifndef SYMBOL_H
#define SYMBOL_H

#include <QGraphicsObject>

class Pitch;

class Symbol : public QGraphicsObject
{
public:
    Symbol( QGraphicsScene *scene );

    enum Length{ NoLength, Whole, Half, Quarter, Eighth, Sixteenth, Thirtysecond };

    void setNextSymbol( const Symbol *symbol );
    void setPrevSymbol( const Symbol *symbol );
    virtual void setLength( Length length );
    virtual bool hasPitch() const;
    virtual void setPitch( const Pitch* pitch );

private:
    const Symbol *m_nextSymbol;
    const Symbol *m_prevSymbol;


protected:
    Length m_length;
    QGraphicsScene *m_scene;
    const Pitch *m_pitch;
};

#endif // SYMBOL_H
