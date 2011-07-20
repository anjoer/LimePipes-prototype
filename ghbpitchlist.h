#ifndef GHBPITCHLIST_H
#define GHBPITCHLIST_H

#include "pitchlist.h"

class GHBPitchList : public PitchList
{
public:
    GHBPitchList( qreal lineHeight );
    enum Pitches{ LowG, LowA, B, C, D, E, F, HighG, HighA };

};

#endif // GHBPITCHLIST_H
