#include "dbmanager.h"
#include <iostream>
using namespace std;

DBManager* DBManager::instance = nullptr;

DBManager::DBManager()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:/Shozda/course-Calendar-of-good-habits/DB.sqlite");
    if(!db.open())
        cout << "DB not open";
}

DBManager *DBManager::getInstance()
{
    if (instance == nullptr)
    {
        instance = new DBManager();
    }
    return instance;
}

QSqlDatabase DBManager::getDB()
{
    return db;
}
