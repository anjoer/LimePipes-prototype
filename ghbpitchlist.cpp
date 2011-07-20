#include "ghbpitchlist.h"
#include "pitch.h"

GHBPitchList::GHBPitchList( qreal lineHeight )
    :PitchList(lineHeight)
{
    m_pitches->insert(LowG, new Pitch("Low G", 3 * lineHeight ));
    m_pitches->insert(LowA, new Pitch("Low A", 2.5 * lineHeight ));
    m_pitches->insert(B, new Pitch("B", 2.0 * lineHeight ));
    m_pitches->insert(C, new Pitch("C", 1.5 * lineHeight ));
    m_pitches->insert(D, new Pitch("D", 1.0 * lineHeight ));
    m_pitches->insert(E, new Pitch("E", 0.5 * lineHeight ));
    m_pitches->insert(F, new Pitch("F", 0.0 ));
    m_pitches->insert(HighG, new Pitch("High G", -0.5 * lineHeight ));
    m_pitches->insert(HighA, new Pitch("High A", -1.0 * lineHeight ));
}


