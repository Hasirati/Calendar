#include "gatheringinf.h"
#include "ui_gatheringinf.h"

gatheringInf::gatheringInf(QWidget *parent)
    : QWidget(parent), ui(new Ui::gatheringInf) {
  ui->setupUi(this);
  ui->rb_yes->close();
  ui->rb_no->close();
  userInfo = new UserInfo();
}

gatheringInf::~gatheringInf() { delete ui; }

void gatheringInf::on_pb_next_clicked() {
  switch (stage) {
  case 1: {
    //        ofstream out("userInfo.txt");
    //            if (!out.is_open())
    //                cout << "File not open" << endl;
    //            else {

    //            }
    //            out.close();
    userInfo->setWakeUp(ui->time->time());
    ui->lb_question->setText(
        "At what time is it \nconvenient for you \nto sum up?");
    ui->time->setTime(QTime(0, 0));
    stage++;
    break;
  }

  case 2: {
    ui->time->close();
    userInfo->setResultDay(ui->time->time());
    ui->time->setTime(QTime(0, 0));
    ui->lb_question->setText("Do you want \nto change?");
    ui->rb_yes->show();
    ui->rb_no->show();
    stage++;
    break;
  }
  case 3: {
    answer = ui->rb_yes->isChecked() + ui->rb_yes->isChecked();
    hide();
    obj.show();
    break;
  }
  }
}
