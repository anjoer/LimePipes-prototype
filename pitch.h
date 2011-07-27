#ifndef PITCH_H
#define PITCH_H

#include <QtGlobal>
#include <QHash>


class QString;

class Pitch
{
public:
    Pitch( const char *name, qreal ypos, qreal lineHeight, QString *desc = 0 );
    ~Pitch();
    qreal getY() const;
    const QString getName() const;
    const QString *getDescription() const;
    qreal getLineHeight() const;
    const Pitch *nextHigher() const;
    const Pitch *nextLower() const;
    void setNextHigher( const Pitch *pitch );
    void setNextLower( const Pitch *pitch );


private:
    const QString *m_name;
    const qreal m_yposition;
    const qreal m_lineHeight;
    const QString *m_description;
    const Pitch *m_nextHigher;
    const Pitch *m_nextLower;

};

#endif // PITCH_H
