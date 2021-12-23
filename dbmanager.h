#ifndef DATABASE_H
#define DATABASE_H

#include <QDate>
#include <QDebug>
#include <QFile>
#include <QList>
#include <QMultiMap>
#include <QObject>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <fstream>
#include <iostream>

#include "challenge.h"
#include "children.h"

#define PICTURE "D:/JULIA/OOP/course/course-Calendar-of-good-habits/picture/"

#define DATABASE_HOSTNAME "DB"
#define DATABASE_LINK                                                          \
  "D:/JULIA/OOP/course/course-Calendar-of-good-habits/DB.sqlite"

#define TABLE "challenge"
#define TABLE_NAME "Name"
#define TABLE_DESCRIPTION "Description"

#define TABLE_1 "children"
#define TABLE_NAME_1 "Name"
#define TABLE_POINTS_1 "Points"
#define TABLE_LINK_1 "link"

#define TABLE_2 "MyChallenge"
#define TABLE_NAME_2 "name "
#define TABLE_DESCRIPTION_2 "description"
#define TABLE_POINTS_2 "points"

#define TABLE_3 "Award"
#define TABLE_NAME_3 "Name"
#define TABLE_POINTS_3 "Points"

class DBManager : public QObject {
  Q_OBJECT
public:
  void connectToDataBase();
  static DBManager *getInstance();
  QList<Challenge> getChellengesList();
  QMultiMap<int, Children *> getChildrensMap();
  Children *getChildrenByName(const QString name);
  void saveToMyChellenge(Children *child);
  QSqlDatabase getDB();

public slots:
  bool inserIntoTable(const QVariantList &);
  bool updateTable(QString);
  bool updateTable(int);
  bool updateTable(const QVariantList &);
  bool deleteTape(const int);

private:
  static DBManager *instance;
  QSqlDatabase db;
  bool openDataBase();
  bool restoreDataBase();
  void closeDataBase();
  bool createTable();
  explicit DBManager(QObject *parent = nullptr);
  ~DBManager();
};

#endif // DATABASE_H
