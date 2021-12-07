#include "dbmanager.h"

DataBase::DataBase(QObject *parent) : QObject(parent)
{}

DataBase::~DataBase(){}

void DataBase::connectToDataBase()
{
    if(!QFile(DATABASE_NAME).exists())
        this->restoreDataBase();
     else
        this->openDataBase();
}

bool DataBase::restoreDataBase()
{
    if(this->openDataBase()){
        if(!this->createTable())
            return false;
         else
            return true;
    } else {
        qDebug() << "Не удалось восстановить базу данных";
        return false;
    }
    return false;
}

bool DataBase::openDataBase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName(DATABASE_HOSTNAME);
    db.setDatabaseName(DATABASE_NAME);
    if(db.open()){
        return true;
    } else {
        return false;
    }
}

void DataBase::closeDataBase()
{
    db.close();
}

bool DataBase::createTable()
{
    QSqlQuery query;
    if(!query.exec( "CREATE TABLE " TABLE " ("
                            "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                            TABLE_NAME      " VARCHAR  NOT NULL,"
                            TABLE_DESCRIPTION     " VARCHAR(255)"
                        " )"
                    )){
        qDebug() << "DataBase: error of create " << TABLE;
        qDebug() << query.lastError().text();
        return false;
    }
    if(!query.exec( "CREATE TABLE " TABLE_1 " ("
                            "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                            TABLE_NAME_1      " VARCHAR            NOT NULL,"
                            TABLE_DESCRIPTION_1     " VARCHAR(255)        "

                        " )"
                    )){
        qDebug() << "DataBase: error of create " << TABLE;
        qDebug() << query.lastError().text();
        return false;
    }
    else {
        return true;
    }
    return false;
}

bool DataBase::updateTable(const QVariantList &data){
    QSqlQuery query;
    query.prepare("UPDATE" TABLE_2 " set " TABLE_NAME_2 " = :name where id = :id");
    query.bindValue(":name",        data[0].toString());
    query.bindValue(":description",      data[1].toInt());

    if(!query.exec()){
        qDebug() << "error insert into " << TABLE;
        qDebug() << query.lastError().text();
        return false;
    } else {
        return true;
    }
    return false;
}

bool DataBase::deleteTape(const int id)
{
    QSqlQuery query;

    query.prepare("DELETE FROM " TABLE " WHERE id= :id ;");
    query.bindValue(":id", id);

    if(!query.exec()){
        qDebug() << "error delete row " << TABLE;
        qDebug() << query.lastError().text();
        return false;
    } else {
        return true;
    }
    return false;
}

bool DataBase::inserIntoTable(const QVariantList &data)
{
    QSqlQuery query;
    query.prepare("INSERT INTO " TABLE " ( " TABLE_NAME ", "
                                             TABLE_DESCRIPTION  " ) "
                  "VALUES (:id, :Name, :Description )");

    query.bindValue(":Name",        data[0].toString());
    query.bindValue(":Description",      data[1].toString());

    if(!query.exec()){
        qDebug() << "error insert into " << TABLE;
        qDebug() << query.lastError().text();
        return false;
    } else {
        return true;
    }
    return false;
}

QSqlDatabase DataBase::getDB()
{
    return db;
}
https://evileg.com/uk/post/189/
