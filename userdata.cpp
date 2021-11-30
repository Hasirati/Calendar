#include "userdata.h"

UserData::UserData()
{
    WHH = 0;
    WMM = 0;
    RHH = 0;
    RMM = 0;
}

void UserData::getWakeUp() {
    cout << "When do you wake up?\n";
    cin >> WHH;
    cin >> WMM;
}

void UserData::getResultDay() {
    cout << "When is it good for you to summarize the day?\n";
    cin >> WHH;
    cin >> WMM;
}

void UserData::getSelfControl() {
    cout << "Do you often put off things for later?\n";
    answer y = Yes;
    switch(y)
    {
        case Yes: cout << "\n";   break;
        case No : cout << "\n"; break;
    }
}

