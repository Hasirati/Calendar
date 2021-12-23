#include "mainwindow.h"
#include <QString>
#include <iostream>

#include "ui_mainwindow.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  conn = DBManager::getInstance();
  conn->connectToDataBase();

  QSqlTableModel *model = new QSqlTableModel();
  model->setTable(TABLE_2);
  ui->tableView->setModel(model);
  model->select();
  qDebug() << (model->rowCount());
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pb_add_clicked() { obj.show(); }

void MainWindow::on_pb_save_clicked() {
  QSqlQuery query;

  QString name, point;
  name = ui->line_name->text();
  point = ui->line_des->text();

  if (query.prepare("SELECT * FROM" TABLE_2 "WHERE name ='" + name +
                    "', points ='" + point + "'")) {
    QMessageBox::warning(this, "I`m sorry, but",
                         "Such a record already exists");
  } else {
    QVariantList data;
    data.append(name);
    data.append(point);
    conn->inserIntoTable(data);
  }
  QSqlTableModel *model = new QSqlTableModel();
  model->setTable(TABLE_2);
  ui->tableView->setModel(model);
  model->select();
  qDebug() << (model->rowCount());
}

void MainWindow::on_pb_update_clicked() {
  QSqlQuery query;

  QString name, id, point;
  id = ui->line_id->text();
  name = ui->line_name->text();
  point = ui->line_des->text();

  if (!query.exec("SELECT * FROM" TABLE_2 "WHERE name ='" + name +
                  "', points ='" + point + "'")) {
    QMessageBox::warning(this, "I`m sorry, but",
                         "Such a record already exists");
  } else {
    QVariantList data;
    data.append(id);
    data.append(name);
    data.append(point);

    if (name != "\0" && point != "\0")
      conn->updateTable(data);
    else if (name == "\0")
      conn->updateTable(point);
    else if (point == "\0")
      conn->updateTable(name);
  }

  QSqlTableModel *model = new QSqlTableModel();
  model->setTable(TABLE_2);
  ui->tableView->setModel(model);
  model->select();
  qDebug() << (model->rowCount());
}

void MainWindow::on_pb_delete_clicked() {
  int id;
  id = ui->line_id->text().toInt();

  conn->deleteTape(id);

  QSqlTableModel *model = new QSqlTableModel();
  model->setTable(TABLE_2);
  ui->tableView->setModel(model);
  model->select();
  qDebug() << (model->rowCount());
}

void MainWindow::on_pb_done_clicked() {
  int id;
  id = ui->line_id->text().toInt();
  conn->deleteTape(id);

  QSqlTableModel *model = new QSqlTableModel();
  model->setTable(TABLE_2);
  ui->tableView->setModel(model);
  model->select();
  qDebug() << (model->rowCount());
}

void MainWindow::on_pb_adward_clicked() { obj1.show(); }
