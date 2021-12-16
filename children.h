#ifndef CHILDREN_H
#define CHILDREN_H

#include "dbmanager.h"
#include <QDebug>

class Children
{
    QString name;
    QString points;
    int link;
public:
    Children();
    Children(QString, QString, int);

    void setName(QString);
    QString getName();

    void setPoints(QString);
    QString getPoints();

    void setLink(int);
    int getLink();
};

#endif // CHILDREN_H
