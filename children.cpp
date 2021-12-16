#include "children.h"

Children::Children()
{

}

Children::Children(QString name, QString points, int link)
{
    this->name = name;
    this->points = points;
    this->link = link;
}

void Children::setName(QString name)
{
    this->name = name;
}

QString Children::getName()
{
    return name;
}

void Children::setPoints(QString description)
{
    this->points = description;
}

QString Children::getPoints()
{
    return points;
}

void Children::setLink(int link)
{
    this->link = link;
}

int Children::getLink()
{
    return link;
}


