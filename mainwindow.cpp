#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pb_add_clicked() { obj.show(); }

void MainWindow::on_pb_save_clicked() {
  DBManager conn;
  QString name, id;
  name = ui->line_name->text();
  id = ui->line_id->text();

  if (!conn.connOpen()) {
    qDebug() << "Not open";
    return;
  }

  conn.connOpen();
  QSqlQuery qry;
  qry.prepare("insert into MyChallenge (id, name) values('" + id + "','" + name +
              "')");

  if (qry.exec()) {
    QMessageBox::about(this, tr("Save"), tr("saved"));
    conn.connClose();
  } else {
    QMessageBox::critical(this, tr("error::"), qry.lastError().text());
  }
}

void MainWindow::on_pb_update_clicked() {
  DBManager conn;
  QString name, id;
  id = ui->line_id->text();
  name = ui->line_name->text();

  if (!conn.connOpen()) {
    qDebug() << "Not open";
    return;
  }

  conn.connOpen();
  QSqlQuery qry;
  qry.prepare("update MyChallenge set Name='" + name + "' where id='" + id + "'");

  if (qry.exec()) {
    QMessageBox::about(this, tr("Edit"), tr("update"));
    conn.connClose();
  } else {
    QMessageBox::critical(this, tr("error::"), qry.lastError().text());
  }
}

void MainWindow::on_pb_delete_clicked() {
  DBManager conn;
  QString id;
  id = ui->line_id->text();

  if (!conn.connOpen()) {
    qDebug() << "Not open";
    return;
  }

  conn.connOpen();
  QSqlQuery qry;
  qry.prepare("Delete from MyChallenge where id='" + id + "'");

  if (qry.exec()) {
    QMessageBox::about(this, tr("Delete"), tr("delete"));
    conn.connClose();
  } else {
    QMessageBox::critical(this, tr("error::"), qry.lastError().text());
  }
}

void MainWindow::on_pb_show_clicked()
{
  DBManager conn;
    conn.connOpen();
    QSqlTableModel *model = new QSqlTableModel();

    model->setTable("MyChallenge");
    ui->tableView->setModel(model);
    model->select();

    conn.connClose();
    qDebug() << (model->rowCount());
}

