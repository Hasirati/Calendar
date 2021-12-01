#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include "dbmanager.h"
#include <QTreeView>

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

private:
  Ui::MainWindow *ui;
  DBManager* dbmanager;

};
#endif // MAINWINDOW_H

//http://www.java2s.com/Code/Cpp/Qt/QTreeViewdemoandQStandardItem.htm
