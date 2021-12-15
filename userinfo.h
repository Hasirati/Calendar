#ifndef USERINFO_H
#define USERINFO_H

#include <QDir>
#include <QString>
#include <QTime>
#include <fstream>
#include <iostream>

using namespace std;

class UserInfo {
  QString getUp;
  QString timeToResault;

public:
  UserInfo();
  void setWakeUp(QTime);
  void setResultDay(QTime);
};

#endif // USERINFO_H
