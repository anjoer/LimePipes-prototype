#include "pitch.h"

Pitch::Pitch(const char *name, qreal ypos, QString *desc)
    :m_yposition(ypos)
{
    m_name = new QString(name);
    m_description = desc;

}

Pitch::~Pitch()
{
    delete m_name;
    delete m_description;
}

qreal Pitch::getY() const
{
    return m_yposition;
}

const QString *Pitch::getName() const
{
    return m_name;
}

const QString *Pitch::getDescription() const
{
    return m_description;
}

