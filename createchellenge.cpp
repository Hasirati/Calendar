#include "createchellenge.h"
#include "mainwindow.h"
#include "ui_createchellenge.h"
#include "dbmanager.h"

CreateChellenge::CreateChellenge(QWidget *parent)
    : QWidget(parent), ui(new Ui::CreateChellenge) {
  ui->setupUi(this);
  ui->lineEdit->close();
  ui->pb_next->close();
}

CreateChellenge::~CreateChellenge() { delete ui; }

void CreateChellenge::on_pb_water_clicked() {
  ui->pb_read->close();
  ui->pb_train->close();
  ui->pb_water->close();
  ui->pb_walk->close();
  ui->label->setText("How many \nglasses a day?");
  ui->lineEdit->show();
  ui->pb_next->show();

  DataBase conn;
  QString name = "Drink water";
  QString des = "\0";
int str = ui->lineEdit->text().toInt();
  des =  QString::number(str) + " glasses a day";
  QVariantList data;
  data.append(name);
  data.append(des);
  conn.inserIntoTable(data);
}

void CreateChellenge::on_pb_walk_clicked() {
  ui->pb_read->close();
  ui->pb_train->close();
  ui->pb_water->close();
  ui->pb_walk->close();
  ui->label->setText("How many \nkilometers?");
  ui->lineEdit->show();
  ui->pb_next->show();

  DataBase conn;
  QString name = "Walk", des = "\0";
  QString str = ui->lineEdit->text();
  QString str1 = " kilometers";
des =  str + " " + str1;
  QVariantList data;
  data.append(name);
    data.append(des);
  conn.inserIntoTable(data);
}

void CreateChellenge::on_pb_train_clicked() {
  ui->pb_read->close();
  ui->pb_train->close();
  ui->pb_water->close();
  ui->pb_walk->close();
  ui->label->setText("How many \nminutes a day?");
  ui->lineEdit->show();
  ui->pb_next->show();

  DataBase conn;
  QString name = "Train", des = "\0";
  QString str = ui->lineEdit->text();
  QString str1 = " minutes a day";
  des = str + " " + str1;
  QVariantList data;
  data.append(name);
    data.append(des);
  conn.inserIntoTable(data);
}

void CreateChellenge::on_pb_read_clicked() {
  ui->pb_read->close();
  ui->pb_train->close();
  ui->pb_water->close();
  ui->pb_walk->close();
  ui->label->setText("How many \npages a day?");
  ui->lineEdit->show();
  ui->pb_next->show();

  DataBase conn;
  QString name = "Read", des = "\0";
    QString str = ui->lineEdit->text();
    QString str1 = " pages a day";
  des =  str + " " + str1;
  QVariantList data;
  data.append(name);
    data.append(des);
  conn.inserIntoTable(data);
}

void CreateChellenge::on_pb_next_clicked() {
  hide();
  obj.show();
}
