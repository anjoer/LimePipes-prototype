#ifndef PITCHLIST_H
#define PITCHLIST_H

#include <QtGlobal>
#include <QHash>

class Pitch;

class QString;

class PitchList
{
public:
    PitchList( qreal lineHeight );
    ~PitchList();

    qreal lineHeight() const;
    const Pitch *getPitch( int pitch ) const;

private:
    qreal m_lineHeight;

protected:
    QHash<int, Pitch*> *m_pitches;
};

#endif // PITCHLIST_H
