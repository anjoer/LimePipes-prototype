#ifndef PITCH_H
#define PITCH_H

#include <QtGlobal>
#include <QHash>


class QString;

class Pitch
{
public:
    Pitch( const char *name, qreal ypos, QString *desc = 0 );
    ~Pitch();
    qreal getY() const;
    const QString *getName() const;
    const QString *getDescription() const;


private:
    const QString *m_name;
    const qreal m_yposition;
    const QString *m_description;

};

#endif // PITCH_H
