#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtSql/QSqlTableModel>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  dbmanager = DBManager::getInstance();
  QSqlTableModel model;
  dbmanager->getDB();
  ui->treeView->close();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pb_add_clicked()
{
    ui->calendar->close();
    ui->pb_add->close();
    ui->lb_ListCallenge->close();
    ui->treeView->show();
}
