#ifndef NOTELENGTH_H
#define NOTELENGTH_H

#include <QVector>

class NoteLength
{
public:
    enum Length{ NoLength=0, Whole=1, Half=2, Quarter=4, Eighth=8, Sixteenth=16, Thirtysecond=32 };
    NoteLength(Length);


    void setLength(Length);
    NoteLength::Length length() const;
    NoteLength operator++(int);
    NoteLength operator--(int);

private:
    QVector<Length> m_lengthVector;
    Length m_length;
    int m_count;
};

#endif // NOTELENGTH_H
