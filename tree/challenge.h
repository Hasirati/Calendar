#ifndef CHALLENGE_H
#define CHALLENGE_H


#define TABLE_chall               "challenge"
#define TABLE_NAME_chall         "Name"
#define TABLE_DESCRIPTION_chall  "Description"


#include "database.h"
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
