#include "challenge.h"

Challenge::Challenge()
{

}

Challenge::Challenge(int id, QString name, QString description)
{
    this->id = id;
    this->name = name;
    this->description = description;
}

int Challenge::getId()
{
    return id;
}

void Challenge::setName(QString name)
{
    this->name = name;
}

QString Challenge::getName()
{
    return name;
}

void Challenge::setDescription(QString description)
{
    this->description = description;
}

QString Challenge::getDescription()
{
    return description;
}


