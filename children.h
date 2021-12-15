#ifndef CHILDREN_H
#define CHILDREN_H

#include "dbmanager.h"
#include <QDebug>

class Children
{
    QString name;
    QString description;
    int link;
public:
    Children();
    Children(QString, QString, int);

    void setName(QString);
    QString getName();

    void setDescription(QString);
    QString getDescription();

    void setLink(int);
    int getLink();
};

#endif // CHILDREN_H
