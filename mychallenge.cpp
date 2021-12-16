#include "mychallenge.h"

MyChallenge::MyChallenge()
{

}

MyChallenge::MyChallenge(QString name, QString points)
{
    this->name = name;
    this->points = points;
}

void MyChallenge::setName(QString name)
{
    this->name = name;
}

QString MyChallenge::getName()
{
    return name;
}

void MyChallenge::setPoints(QString description)
{
    this->points = description;
}

QString MyChallenge::getPoints()
{
    return points;
}
