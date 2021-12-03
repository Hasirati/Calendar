#ifndef LOGIN_H
#define LOGIN_H

#include "emplpyeeinfo.h"
#include <QFileInfo>
#include <QMainWindow>
#include <QtDebug>
#include <QtSql>

QT_BEGIN_NAMESPACE
namespace Ui {
class Login;
}
QT_END_NAMESPACE

class Login : public QMainWindow {
  Q_OBJECT

public:
  QSqlDatabase mydb;

  //походу закриває
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

public:
  Login(QWidget *parent = nullptr);
  ~Login();

private slots:
  void on_pushButton_clicked();

private:
  Ui::Login *ui;
};
#endif // LOGIN_H
