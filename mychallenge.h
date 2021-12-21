#ifndef MYCHALLENGE_H
#define MYCHALLENGE_H
#include <QDebug>

class MyChallenge
{
    int id;
    QString name;
    int points;

public:
    MyChallenge();
    MyChallenge(int id, QString name, int points);

    int getId();
    void setName(QString name);
    QString getName();

    void setPoints(int points);
    int getPoints();
};

#endif // MYCHALLENGE_H
