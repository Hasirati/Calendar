#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>

class DBManager {
  QSqlDatabase db;

  static DBManager *instance;

public:
  DBManager();
  static DBManager *getInstance();
  QSqlDatabase getDB();

  DBManager(DBManager &other) = delete;
  void operator=(const DBManager &) = delete;
};

#endif // DBMANAGER_H
