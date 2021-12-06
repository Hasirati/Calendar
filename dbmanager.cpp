#include "dbmanager.h"

DBManager::DBManager() {
  mydb = QSqlDatabase::addDatabase("QSQLITE");
  mydb.setDatabaseName(
      "D:/Shozda/course-Calendar-of-good-habits/DB.sqlite");
}
