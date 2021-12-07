#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>

#define DATABASE_HOSTNAME   "ExampleDataBase"
#define DATABASE_NAME       "DB.sqlite"

#define TABLE               "challenge"
#define TABLE_NAME          "Name"
#define TABLE_DESCRIPTION   "Description"

#define TABLE_1             "children"
#define TABLE_NAME_1          "Name "
#define TABLE_DESCRIPTION_1   "Description"
#define TABLE_LINK_1   "link"

#define TABLE_2             "MyChallenge"
#define TABLE_NAME_2          "name "
#define TABLE_DESCRIPTION_2   "description"


class DataBase : public QObject
{
    Q_OBJECT
public:
    explicit DataBase(QObject *parent = 0);
~DataBase();
    void connectToDataBase();
    bool inserIntoTable(const QVariantList &);
    bool updateTable(const QVariantList &);
    bool deleteTape(const int);
    QSqlDatabase getDB();

private:
    QSqlDatabase    db;

private:
    bool openDataBase();
    bool restoreDataBase();
    void closeDataBase();
    bool createTable();
};

#endif // DATABASE_H
