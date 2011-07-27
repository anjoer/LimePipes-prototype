#include "pitch.h"

Pitch::Pitch(const char *name, qreal ypos, qreal lineHeight, QString *desc)
    :m_yposition(ypos), m_lineHeight(lineHeight), m_nextHigher(0), m_nextLower(0)
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

const QString Pitch::getName() const
{
    return *m_name;
}

const QString *Pitch::getDescription() const
{
    return m_description;
}

qreal Pitch::getLineHeight() const
{
    return m_lineHeight;
}

const Pitch *Pitch::nextHigher() const
{
    return m_nextHigher;
}

const Pitch *Pitch::nextLower() const
{
    return m_nextLower;
}

void Pitch::setNextHigher(const Pitch *pitch)
{
    m_nextHigher = pitch;
}

void Pitch::setNextLower(const Pitch *pitch)
{
    m_nextLower = pitch;
}
