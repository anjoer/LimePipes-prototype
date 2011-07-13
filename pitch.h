#ifndef PITCH_H
#define PITCH_H

#include <QtGlobal>
#include <QHash>


class QString;

class Pitch
{
public:
    Pitch( qreal lineHeight );

private:
    qreal m_lineHeight;

protected:
    QHash<QString, qreal> *m_pitches;
};

#endif // PITCH_H
