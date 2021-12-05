#include "dbmanager.h"

DBManager::DBManager() {
  mydb = QSqlDatabase::addDatabase("QSQLITE");
  mydb.setDatabaseName(
      "D:/JULIA/OOP/course/course-Calendar-of-good-habits/DB.sqlite");
}
