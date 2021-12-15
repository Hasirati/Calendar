#include "createchellenge.h"
#include "dbmanager.h"
#include "mainwindow.h"
#include "ui_createchellenge.h"

CreateChellenge::CreateChellenge(QWidget *parent)
    : QWidget(parent), ui(new Ui::CreateChellenge) {
  ui->setupUi(this);
}

CreateChellenge::~CreateChellenge() { delete ui; }

void CreateChellenge::on_pb_water_clicked() {
  DataBase conn;

  QString name = "Drink water";
  int point = 20;

  QVariantList data;
  data.append(name);
  data.append(point);
  conn.inserIntoTable(data);

  hide();
  obj.show();
}

void CreateChellenge::on_pb_walk_clicked() {

  DataBase conn;

  QString name = "Walk";
  int point = 15;

  QVariantList data;
  data.append(name);
  data.append(point);
  conn.inserIntoTable(data);

  hide();
  obj.show();
}

void CreateChellenge::on_pb_train_clicked() {
  DataBase conn;

  QString name = "Train";
  int point = 15;

  QVariantList data;
  data.append(name);
  data.append(point);
  conn.inserIntoTable(data);

  hide();
  obj.show();
}

void CreateChellenge::on_pb_read_clicked() {
  DataBase conn;
  QString name = "Read";
  int point = 10;

  QVariantList data;
  data.append(name);
  data.append(point);
  conn.inserIntoTable(data);

  hide();
  obj.show();
}
