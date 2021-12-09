#ifndef USERINFO_H
#define USERINFO_H

#include <QTime>
#include <fstream>
#include <QDir>
#include <QString>
#include <iostream>
using namespace std;

class UserInfo {
  QTime getUp;
  QTime timeToResault;

public:
  UserInfo();
  void setWakeUp(QTime);
  void setResultDay(QTime);
};

#endif // USERINFO_H
