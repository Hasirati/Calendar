#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>
#include <QtDebug>

class DBManager {

public:
  DBManager();
  QSqlDatabase mydb;

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
};

#endif // DBMANAGER_H
