#include "userinfo.h"
#include <QTextStream>
#include <QTime>

UserInfo::UserInfo() {}

void UserInfo::setWakeUp(QTime time) {

    QTextStream out(stdout);

    ofstream in("myfile.txt");
        if (!in.is_open())
            cout << "File not open" << endl;
        else {
            getUp = time;
            out << getUp.toString("hh:mm");
        }
}

void UserInfo::setResultDay(QTime time) { timeToResault = time; }
