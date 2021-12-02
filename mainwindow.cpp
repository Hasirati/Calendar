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

void MainWindow::on_pb_add_clicked() {
  ui->calendar->close();
  ui->pb_add->close();
  ui->lb_ListCallenge->close();
  ui->treeView->show();
  DBManager conn;
  QSqlQueryModel *modal = new QSqlQueryModel;

  conn.show();
  QSqlQuery
}
// https://www.youtube.com/watch?v=nZ9Mejld2lI&list=PLS1QulWo1RIZjrD_OLju84cUaUlLRe5jQ&index=14
// https://www.youtube.com/watch?v=OrHitqwJu8Q&list=PLS1QulWo1RIZjrD_OLju84cUaUlLRe5jQ&index=18
// https://www.youtube.com/watch?v=NJNl4eUa3Xc&list=PLS1QulWo1RIZjrD_OLju84cUaUlLRe5jQ&index=20
