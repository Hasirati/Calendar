#include "dbmanager.h"

DataBase::DataBase(QObject *parent) : QObject(parent) {}

DataBase::~DataBase() {}

void DataBase::connectToDataBase() {
  if (!QFile(
           "D:/JULIA/OOP/course/course-Calendar-of-good-habits/" DATABASE_NAME)
           .exists())
    this->restoreDataBase();
  else
    this->openDataBase();
}

bool DataBase::restoreDataBase() {
  if (this->openDataBase()) {
    return (this->createTable()) ? true : false;
  } else {
    qDebug() << "Не удалось восстановить базу данных";
    return false;
  }
  return false;
}

bool DataBase::openDataBase() {
  db = QSqlDatabase::addDatabase("QSQLITE");
  db.setHostName(DATABASE_HOSTNAME);
  db.setDatabaseName(
      "D:/JULIA/OOP/course/course-Calendar-of-good-habits/" DATABASE_NAME);
  if (db.open()) {
    return true;
  } else {
    return false;
  }
}

void DataBase::closeDataBase() { db.close(); }

bool DataBase::createTable() {
  QSqlQuery query;
  if (!query.exec("CREATE TABLE " TABLE " ("
                  "id INTEGER PRIMARY KEY AUTOINCREMENT, " TABLE_NAME
                  " VARCHAR  NOT NULL," TABLE_DESCRIPTION " VARCHAR(255)"
                  " )")) {
    qDebug() << "DataBase: error of create " << TABLE;
    qDebug() << query.lastError().text();
    return false;
  }

  if (!query.exec("CREATE TABLE " TABLE_1 " ("
                  "id INTEGER PRIMARY KEY AUTOINCREMENT, " TABLE_NAME_1
                  " VARCHAR(255) NOT NULL," TABLE_DESCRIPTION_1
                  " VARCHAR(255), " TABLE_LINK_1 "INTEGER NOT NULL"
                  " )")) {
    qDebug() << "DataBase: error of create " << TABLE;
    qDebug() << query.lastError().text();
    return false;
  }
  if (!query.exec("CREATE TABLE " TABLE_2 " ("
                  "id INTEGER PRIMARY KEY AUTOINCREMENT, " TABLE_NAME_2
                  " VARCHAR(255) NOT NULL," TABLE_DESCRIPTION_2 " VARCHAR(255) "
                  " )")) {
    qDebug() << "DataBase: error of create " << TABLE;
    qDebug() << query.lastError().text();
    return false;
  } else {
    return true;
  }
  return false;
}

bool DataBase::updateTable(const QVariantList &data) {
  QSqlQuery query;
  query.prepare("UPDATE" TABLE_2 " set " TABLE_NAME_2
                " = :name," TABLE_DESCRIPTION_2
                " = :description where id = :id");
  query.bindValue(":name", data[0].toString());
  query.bindValue(":description", data[1].toInt());

  if (!query.exec()) {
    qDebug() << "error insert into " << TABLE;
    qDebug() << query.lastError().text();
    return false;
  } else {
    return true;
  }
  return false;
}

bool DataBase::deleteTape(const int id) {
  QSqlQuery query;

  query.prepare("DELETE FROM " TABLE_2 " WHERE id= :id ;");
  query.bindValue(":id", id);

  if (!query.exec()) {
    qDebug() << "error delete row " << TABLE;
    qDebug() << query.lastError().text();
    return false;
  } else {
    return true;
  }
  return false;
}

bool DataBase::inserIntoTable(const QVariantList &data) {
  QSqlQuery query;
  query.prepare("INSERT INTO " TABLE_2 " ( " TABLE_NAME_2
                ", " TABLE_DESCRIPTION_2 " ) "
                "VALUES (:name, :description)");
  query.bindValue(":name", data[0].toString());
  query.bindValue(":description", data[1].toString());

  if (!query.exec()) {
    qDebug() << "error insert into " << TABLE;
    qDebug() << query.lastError().text();
    return false;
  } else {
    return true;
  }
  return false;
}

QSqlDatabase DataBase::getDB() { return db; }
