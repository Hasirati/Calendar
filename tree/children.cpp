#include "children.h"

Children::Children()
{

}

Children::Children(QString name, QString description, int link)
{
    this->name = name;
    this->description = description;
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

void Children::setDescription(QString description)
{
    this->description = description;
}

QString Children::getDescription()
{
    return description;
}

void Children::setLink(int link)
{
    this->link = link;
}

int Children::getLink()
{
    return link;
}


