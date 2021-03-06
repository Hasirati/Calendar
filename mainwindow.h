#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "adward.h"
#include "dbmanager.h"
#include "mychallenge.h"
#include "treeview.h"

#include <QDebug>
#include <QDialog>
#include <QFile>
#include <QFileInfo>
#include <QMainWindow>
#include <QMessageBox>
#include <QObject>
#include <QSqlQueryModel>
#include <QWidget>
#include <QtSql>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private slots:
  void on_pb_add_clicked();
  void on_pb_save_clicked();
  void on_pb_update_clicked();
  void on_pb_delete_clicked();
  void on_pb_done_clicked();
  void on_pb_adward_clicked();

private:
  Ui::MainWindow *ui;
  DBManager *conn;
  TreeView obj;
  Adward obj1;
};
#endif // MAINWINDOW_H
