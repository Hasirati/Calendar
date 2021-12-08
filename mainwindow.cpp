#include "mainwindow.h"
#include "dbmanager.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  DataBase conn;
  conn.connectToDataBase();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pb_add_clicked() { obj.show(); }

void MainWindow::on_pb_save_clicked() {
  QSqlQuery query;

  DataBase conn;
  QString name, des;
  name = ui->line_name->text();
  des = ui->line_des->text();

  if (!query.exec("SELECT * FROM" TABLE_2 "WHERE name ='" +name+"', description ='" +des+ "'")) {
    QMessageBox::warning(this, "I`m sorry, but", "Such a record already exists");
  }
  else {
  QVariantList data;
  data.append(name);
  data.append(des);

  conn.inserIntoTable(data);
  }
}

void MainWindow::on_pb_update_clicked() {
    QSqlQuery query;

  DataBase conn;
  QString name, id, des;
  id = ui->line_id->text();
  name = ui->line_name->text();
  des = ui->line_des->text();

  if (!query.exec("SELECT * FROM" TABLE_2 "WHERE name ='" +name+"', description ='" +des+ "'")) {
    QMessageBox::warning(this, "I`m sorry, but", "Such a record already exists");
  }
  else {
  QVariantList data;
  data.append(id);
  data.append(name);
  data.append(des);

  conn.updateTable(data);
  }
}

void MainWindow::on_pb_delete_clicked() {
  DataBase conn;
  int id;
  id = ui->line_id->text().toInt();

  conn.deleteTape(id);
}

void MainWindow::on_pb_show_clicked() {
  QSqlTableModel *model = new QSqlTableModel();

  model->setTable(TABLE_2);
  ui->tableView->setModel(model);
  model->select();
  qDebug() << (model->rowCount());

  // this->setQuery("SELECT " TABLE_2 ", " TABLE_DESCRIPTION_2 " FROM "
  // TABLE_2);
}
