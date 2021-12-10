#include "userinfo.h"
#include <QTextStream>
#include <QTime>

UserInfo::UserInfo() {}

void UserInfo::setWakeUp(QTime time) {
  //не записується у файл, можу лише вивести
  QTextStream out(stdout);

  ofstream in("myfile.txt");
  if (!in.is_open())
    cout << "File not open" << endl;
  else {
    getUp = time;
    // in << getUp.toString("hh:mm");
    out << getUp.toString("hh:mm");
  }
}

void UserInfo::setResultDay(QTime time) {
  QTextStream out(stdout);

  ofstream in("myfile.txt");
  if (!in.is_open())
    cout << "File not open" << endl;
  else {
    timeToResault = time;
    // in << getUp.toString("hh:mm");
    out << getUp.toString("hh:mm");
  }
}
