#include "dbmanager.h"

DBManager *DBManager::instance = nullptr;

DBManager::DBManager(QObject *parent) : QObject(parent) {
  db = QSqlDatabase::addDatabase("QSQLITE");
  db.setHostName(DATABASE_HOSTNAME);
  db.setDatabaseName(DATABASE_LINK);
}

DBManager::~DBManager() {}

void DBManager::connectToDataBase() {
  if (!db.isOpen()) {
    if (!QFile(DATABASE_LINK).exists())
      this->restoreDataBase();
    else
      this->openDataBase();
  }
}

DBManager *DBManager::getInstance() {
  if (instance == nullptr) {
    instance = new DBManager();
  }
  return instance;
}

bool DBManager::restoreDataBase() {
  if (this->openDataBase()) {
    return (this->createTable()) ? true : false;
  } else {
    qDebug() << "Failed to restore database";
    return false;
  }
  return false;
}

bool DBManager::openDataBase() {
  if (db.open()) {
    return true;
  } else {
    return false;
  }
}

void DBManager::closeDataBase() { db.close(); }

bool DBManager::createTable() {
  QSqlQuery query;
  if (!query.exec("CREATE TABLE " TABLE " ("
                  "id INTEGER PRIMARY KEY AUTOINCREMENT, " TABLE_NAME
                  " VARCHAR  NOT NULL, " TABLE_DESCRIPTION " VARCHAR(255)"
                  " )")) {
    qDebug() << "DataBase: error of create " << TABLE;
    qDebug() << query.lastError().text();
    return false;
  }

  if (!query.exec("CREATE TABLE " TABLE_1 " ("
                  "id INTEGER PRIMARY KEY AUTOINCREMENT, " TABLE_NAME_1
                  " VARCHAR(255) NOT NULL, " TABLE_POINTS_1
                  " INTEGER NOT NULL, " TABLE_LINK_1 " INTEGER NOT NULL"
                  " )")) {
    qDebug() << "DataBase: error of create " << TABLE;
    qDebug() << query.lastError().text();
    return false;
  }
  if (!query.exec("CREATE TABLE " TABLE_2 " ("
                  "id INTEGER PRIMARY KEY AUTOINCREMENT, " TABLE_NAME_2
                  " VARCHAR(255) NOT NULL, " TABLE_DESCRIPTION_2
                  " VARCHAR(255), " TABLE_POINTS_1 " INTEGER NOT NULL)")) {
    qDebug() << "DataBase: error of create " << TABLE;
    qDebug() << query.lastError().text();
    return false;
  }
  if (!query.exec("CREATE TABLE " TABLE_3 " ("
                  "id INTEGER PRIMARY KEY AUTOINCREMENT, " TABLE_NAME_3
                  " VARCHAR(255) NOT NULL, " TABLE_POINTS_1
                  " INTEGER NOT NULL)")) {
    qDebug() << "DataBase: error of create " << TABLE;
    qDebug() << query.lastError().text();
    return false;
  } else {
    return true;
  }
}

bool DBManager::updateTable(const QVariantList &data) {
  QSqlQuery query;
  query.prepare("UPDATE " TABLE_2 " set " TABLE_NAME_2
                " = :name, " TABLE_POINTS_2 " = :points where id = :id");
  query.bindValue(":id", data[0].toInt());
  query.bindValue(":name", data[1].toString());
  query.bindValue(":points", data[2].toInt());

  if (!query.exec()) {
    qDebug() << "error update into " << TABLE_2;
    qDebug() << query.lastError().text();
    return false;
  } else {
    return true;
  }
  return false;
}

bool DBManager::updateTable(const QString date) {
  QSqlQuery query;
  query.prepare("UPDATE " TABLE_2 " set " TABLE_NAME_2 "= :name");
  query.bindValue(":name", date);

  if (!query.exec()) {
    qDebug() << "error insert into " << TABLE;
    qDebug() << query.lastError().text();
    return false;
  } else {
    return true;
  }
  return false;
}

bool DBManager::updateTable(const int date) {
  QSqlQuery query;
  query.prepare("UPDATE " TABLE_2 " set " TABLE_POINTS_2 "= :points");
  query.bindValue(":points", date);

  if (!query.exec()) {
    qDebug() << "error insert into " << TABLE;
    qDebug() << query.lastError().text();
    return false;
  } else {
    return true;
  }
  return false;
}

bool DBManager::deleteTape(const int id) {
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

bool DBManager::inserIntoTable(const QVariantList &data) {
  QSqlQuery query;
  query.prepare("INSERT INTO " TABLE_2 " ( " TABLE_NAME_2 ", " TABLE_POINTS_2
                " ) "
                "VALUES (:name, :points)");
  query.bindValue(":name", data[0].toString());
  query.bindValue(":points", data[1].toInt());

  if (!query.exec()) {
    qDebug() << "error insert into " << TABLE;
    qDebug() << query.lastError().text();
    return false;
  } else {
    return true;
  }
  return false;
}

QSqlDatabase DBManager::getDB() { return db; }

QList<Challenge> DBManager::getChellengesList() {
  QSqlQuery query = QSqlQuery(db);
  QList<Challenge> challengesList;
  if (!query.exec("SELECT * FROM " TABLE)) {
    qDebug() << "error insert into " << TABLE;
    qDebug() << query.lastError().text();
  }
  while (query.next()) {
    int id = query.value("id").toInt();
    QString name = query.value("Name").toString();
    QString desc = query.value("Description").toString();
    Challenge challenge(id, name, desc);
    challengesList.push_back(challenge);
  }
  return challengesList;
}

QMultiMap<int, Children *> DBManager::getChildrensMap() {
  QSqlQuery query = QSqlQuery(db);
  QMultiMap<int, Children *> childrensList;
  if (!query.exec("SELECT * FROM " TABLE_1)) {
    qDebug() << "error SELECT * FROM " << TABLE_1;
    qDebug() << query.lastError().text();
  }
  while (query.next()) {
    int id = query.value("id").toInt();
    QString name = query.value("Name").toString();
    int points = query.value("Points").toInt();
    int link = query.value("link").toInt();
    Children *children = new Children(id, name, points, link);
    childrensList.insert(children->getLink(), children);
  }
  return childrensList;
}

Children *DBManager::getChildrenByName(const QString name) {
  QSqlQuery query = QSqlQuery(db);
  Children *children = new Children();
  if (!query.exec("SELECT * FROM " TABLE_1 " WHERE Name= '" + name + "'")) {
    qDebug() << "error SELECT * FROM " << TABLE_1;
    qDebug() << query.lastQuery();
    qDebug() << query.lastError().text();
  }
  while (query.next()) {
    int id = query.value("id").toInt();
    QString name = query.value("Name").toString();
    int points = query.value("Points").toInt();
    int link = query.value("link").toInt();
    delete children;
    children = new Children(id, name, points, link);
  }
  return children;
}

void DBManager::saveToMyChellenge(Children *child) {
  QSqlQuery query = QSqlQuery(db);
  query.prepare("INSERT INTO " TABLE_2 " ( " TABLE_NAME_2 ", " TABLE_POINTS_2
                " ) VALUES (:name, :points)");
  query.bindValue(":name", child->getName());
  query.bindValue(":points", child->getPoints());

  if (!query.exec()) {
    qDebug() << "error insert into " << TABLE;
    qDebug() << query.lastError().text();
  }
}
