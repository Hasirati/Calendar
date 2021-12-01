#ifndef USERINFO_H
#define USERINFO_H

#include <iostream>
#include <QTime>
using namespace std;

class UserInfo
{
    QTime getUp;
    QTime timeToResault;

public:
    UserInfo();
    void setWakeUp(QTime);
    void setResultDay();

};

#endif // USERINFO_H
