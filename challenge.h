#ifndef CHALLENGE_H
#define CHALLENGE_H

#include "dbmanager.h"
#include <QDebug>

class Challenge
{
    QString name;
    QString description;
public:
    Challenge();
    Challenge(QString, QString);

    void setName(QString name);
    QString getName();

    void setDescription(QString);
    QString getDescription();

};

#endif // CHALLENGE_H
