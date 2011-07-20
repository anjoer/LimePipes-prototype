#include "pitchlist.h"
#include "pitch.h"

PitchList::PitchList(qreal lineHeight)
{
    m_lineHeight = lineHeight;
    m_pitches = new QHash<int, Pitch*>;
}

PitchList::~PitchList()
{
    delete m_pitches;
}

qreal PitchList::lineHeight() const
{
    return m_lineHeight;
}

const Pitch *PitchList::getPitch(int pitch) const
{
    return m_pitches->value(pitch);
}
