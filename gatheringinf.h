#ifndef GATHERINGINF_H
#define GATHERINGINF_H

#include "createchellenge.h"
#include "userinfo.h"
#include <QMessageBox>
#include <QString>
#include <QWidget>
#include <fstream>
#include <iostream>
using namespace std;

namespace Ui {
class gatheringInf;
}

class gatheringInf : public QWidget {
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
