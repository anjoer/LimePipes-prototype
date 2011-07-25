#ifndef EMBELLISHMENT_H
#define EMBELLISHMENT_H

#include "melodysymbol.h"

class Embellishment : public MelodySymbol
{
public:
    Embellishment( QGraphicsScene *scene, const QPen *pen );
};

#endif // EMBELLISHMENT_H
