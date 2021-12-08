#include "challenge.h"

Challenge::Challenge()
{

}

Challenge::Challenge(QString name, QString description)
{
    this->name = name;
    this->description = description;
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


