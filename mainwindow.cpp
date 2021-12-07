#include "mainwindow.h"
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
  DataBase conn;
  QString name, id;
  name = ui->line_name->text();
  id = ui->line_id->text();

  conn.inserIntoTable();

}

void MainWindow::on_pb_update_clicked() {
  DataBase conn;
  QString name, id, descrip;
  id = ui->line_id->text();
  name = ui->line_name->text();
  descrip = ui->line_des->text();

    conn.updateTable();
}

void MainWindow::on_pb_delete_clicked() {
  DataBase conn;
  int id;
  id = ui->line_id->text().toInt();

  conn.deleteTape(id);
}

void MainWindow::on_pb_show_clicked()
{
    QSqlTableModel *model = new QSqlTableModel();

    model->setTable("MyChallenge");
    ui->tableView->setModel(model);
    model->select();
    qDebug() << (model->rowCount());
}

