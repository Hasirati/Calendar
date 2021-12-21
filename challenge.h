#ifndef CHALLENGE_H
#define CHALLENGE_H

#include <QDebug>

class Challenge
{
    int id;
    QString name;
    QString description;

public:
    Challenge();
    Challenge(int id, QString name, QString description);

    int getId();
    void setName(QString name);
    QString getName();

    void setDescription(QString);
    QString getDescription();

};

#endif // CHALLENGE_H
