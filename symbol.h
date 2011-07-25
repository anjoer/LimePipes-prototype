#ifndef SYMBOL_H
#define SYMBOL_H

#include <QGraphicsWidget>

class Pitch;

class Symbol : public QGraphicsWidget
{
public:
    Symbol( QGraphicsScene *scene, const QPen *pen );

    enum Length{ NoLength, Whole, Half, Quarter, Eighth, Sixteenth, Thirtysecond };

    void setNextSymbol( const Symbol *symbol );
    void setPrevSymbol( const Symbol *symbol );
    virtual void setLength( Length length );
    virtual bool hasPitch() const;
    virtual void setPitch( const Pitch* pitch );
    const Pitch *pitch() const;

private:
    const Symbol *m_nextSymbol;
    const Symbol *m_prevSymbol;


protected:
    Length m_length;
    QGraphicsScene *m_scene;
    const Pitch *m_pitch;
    const QPen *m_pen;


};

#endif // SYMBOL_H
