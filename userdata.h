#ifndef USERDATA_H
#define USERDATA_H

#include <ctime>
#include <iostream>
using namespace std;

class UserData
{
    int WHH, WMM;
    int RHH, RMM;
    enum answer {Yes, No};

public:
    UserData();
    void getWakeUp();
    void getResultDay();
    void getSelfControl();
};

#endif // USERDATA_H
