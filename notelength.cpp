#include "notelength.h"
#include <QDebug>

NoteLength::NoteLength(Length length)
    :m_length(length)
{
    m_lengthVector.append(Thirtysecond);
    m_lengthVector.append(Sixteenth);
    m_lengthVector.append(Eighth);
    m_lengthVector.append(Quarter);
    m_lengthVector.append(Half);
    m_lengthVector.append(Whole);

    m_count = m_lengthVector.size();
    m_length = length;
}

NoteLength::Length NoteLength::length() const
{
    return m_length;
}

void NoteLength::setLength(Length length)
{
    m_length = length;
}

NoteLength NoteLength::operator++(int)
{
    Length oldLength = m_length;
    int idx = m_lengthVector.indexOf(m_length);
    if(idx != -1){  //Länge vorhanden
        if(idx != m_count-1){ //Weitere Längen vorhanden
            idx++;
            m_length = m_lengthVector.at(idx);
        }
    }
    return oldLength;
}

NoteLength NoteLength::operator--(int)
{
    Length oldLength = m_length;
    int idx = m_lengthVector.indexOf(m_length);
    if(idx != -1){  //Länge vorhanden
        if(idx != 0){ //Weitere Längen vorhanden
            idx--;
            m_length = m_lengthVector.at(idx);
        }
    }
    return oldLength;
}
