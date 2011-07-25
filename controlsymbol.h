#ifndef CONTROLSYMBOL_H
#define CONTROLSYMBOL_H

#include "symbol.h"

class ControlSymbol : public Symbol
{
public:
    ControlSymbol( QGraphicsScene *scene, const QPen *pen );
};

#endif // CONTROLSYMBOL_H
