#include "ghbpitch.h"

GHBPitch::GHBPitch( qreal lineHeight )
    :Pitch( lineHeight )
{
    m_pitches = new QHash<QString, qreal>;
    m_pitches->insert("Low G",  3    * lineHeight);
    m_pitches->insert("Low A",  2.5  * lineHeight);
    m_pitches->insert("B",      2    * lineHeight);
    m_pitches->insert("C",      1.5  * lineHeight);
    m_pitches->insert("D",      1    * lineHeight);
    m_pitches->insert("E",      0.5  * lineHeight);
    m_pitches->insert("F",      0.0);
    m_pitches->insert("High G", -0.5 * lineHeight);
    m_pitches->insert("High A", -1   * lineHeight);
}
