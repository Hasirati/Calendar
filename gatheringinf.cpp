#include "gatheringinf.h"
#include "dbmanager.h"
#include "ui_gatheringinf.h"
#include <QMessageBox>

GatheringInf::GatheringInf(QWidget *parent)
    : QWidget(parent), ui(new Ui::gatheringInf) {
  ui->setupUi(this);
  ui->rb_yes->close();
  ui->rb_no->close();
  userInfo = new UserInfo();

  QPixmap pix(PICTURE "wake-up.jpg");
  ui->lb_pic->setPixmap(pix);
}

GatheringInf::~GatheringInf() { delete ui; }

void GatheringInf::on_pb_next_clicked() {
  switch (stage) {
  case 1: {
    QPixmap pix(PICTURE "sum-up.png");
    ui->lb_pic->setPixmap(pix);

    userInfo->setWakeUp(ui->time->time());
    ui->lb_question->setText(
        "At what time is it \nconvenient for you \nto sum up?");
    ui->time->setTime(QTime(0, 0));
    stage++;
    break;
  }

  case 2: {
    QPixmap pix(PICTURE "two-paths.jpg");
    ui->lb_pic->setPixmap(pix);

    ui->time->close();
    userInfo->setResultDay(ui->time->time());
    ui->time->setTime(QTime(0, 0));
    ui->lb_question->setText("Do you want \nto change?");
    ui->rb_yes->show();
    ui->rb_no->show();
    ui->pb_next->close();
    stage++;
    break;
  }
  }
}

void GatheringInf::on_rb_no_clicked() {
  QMessageBox::warning(this, "I`m sorry, but", "\tYou gave up too early!\t");
  QApplication::exit();
}

void GatheringInf::on_rb_yes_clicked() {
  answer = ui->rb_yes->isChecked() + ui->rb_yes->isChecked();
  hide();
  obj.show();
}
