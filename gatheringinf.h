#ifndef GATHERINGINF_H
#define GATHERINGINF_H

#include <QWidget>
#include <QString>
#include <iostream>
#include "userinfo.h"
#include <fstream>
#include <QMessageBox>
#include "createchellenge.h"
using namespace std;

namespace Ui {
class gatheringInf;
}

class gatheringInf : public QWidget
{
    Q_OBJECT

public:
    explicit gatheringInf(QWidget *parent = nullptr);
    ~gatheringInf();


private slots:
    void on_pb_next_clicked();

private:
    Ui::gatheringInf *ui;
    UserInfo *userInfo;
    int stage = 1;
    bool answer;
    CreateChellenge obj;
};

#endif // GATHERINGINF_H
