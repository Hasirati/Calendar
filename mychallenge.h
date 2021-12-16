#ifndef MYCHALLENGE_H
#define MYCHALLENGE_H
#include <QDebug>

class MyChallenge
{
    int id;
    QString name;
    QString points;

public:
    MyChallenge();
    MyChallenge(QString name, QString points);

    int getId();
    void setName(QString name);
    QString getName();

    void setPoints(QString points);
    QString getPoints();
};

#endif // MYCHALLENGE_H
