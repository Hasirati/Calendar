#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QMessageBox>

class QTreeWidget;
class QTreeWidgetItem;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:

  QSqlDatabase mydb;

  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

  //закриває
  void connClose() {
    mydb.close();
    mydb.removeDatabase(QSqlDatabase::defaultConnection);
  }

  //відкриває
  bool connOpen() {

    //перевірка
    if (!mydb.open()) {
      qDebug() << "Not open";
      return false;
    } else {
      qDebug() << "Connected";
      return true;
    }
  }

  virtual void process(QTreeWidget *tree_widget, QTreeWidgetItem *tree_item);
private slots:
  void on_pushButton_clicked();

private:
  Ui::MainWindow *ui;

  bool listwidget_exists_item(const QString &item) const;
};
#endif // MAINWINDOW_H
