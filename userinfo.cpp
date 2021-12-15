#include "userinfo.h"

UserInfo::UserInfo() {}

void UserInfo::setWakeUp(QTime time) {

  ofstream in("myfile.txt");
  if (!in.is_open())
    cout << "File not open" << endl;
  else {
    getUp = time.toString("hh:mm\n");
    in << &getUp;
  }
  in.close();
}

void UserInfo::setResultDay(QTime time) {

  ofstream in("myfile.txt");
  if (!in.is_open())
    cout << "File not open" << endl;
  else {
    timeToResault = time.toString("hh:mm");
    in << &timeToResault;
  }
  in.close();
}
