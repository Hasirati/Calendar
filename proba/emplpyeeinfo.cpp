#include "emplpyeeinfo.h"
#include "ui_emplpyeeinfo.h"

EmplpyeeInfo::EmplpyeeInfo(QWidget *parent)
    : QDialog(parent), ui(new Ui::EmplpyeeInfo) {
  ui->setupUi(this);

  //перевіряю чи відкриваю файл
  Login conn;
  if (!conn.connOpen())
    ui->label_3->setText("Not open");
  else
    ui->label_3->setText("Connected");
}

EmplpyeeInfo::~EmplpyeeInfo() { delete ui; }

//зберігає в базу даних
void EmplpyeeInfo::on_pushButton_clicked() {
  Login conn;
  QString name, opuc;
  name = ui->lineEdit_1->text();
  opuc = ui->lineEdit_4->text();

  if (!conn.connOpen()) {
    qDebug() << "Not open";
    return;
  }

  conn.connOpen();
  //доступ до файлу
  QSqlQuery qry;
  //добавлення в файл
  qry.prepare("insert into challenge (Name, Description) values('" + name +
              "','" + opuc + "')");
  //дані де не NOT NULL, обов'язково заповнити
  if (qry.exec()) {
    QMessageBox::critical(this, tr("Save"), tr("saved"));
    conn.connClose();
  } else {
    QMessageBox::critical(this, tr("error::"), qry.lastError().text());
  }
}

//оновлення даних
void EmplpyeeInfo::on_pushButton_2_clicked() {
  Login conn;
  QString name, opuc, idn;
  idn = ui->lineEdit->text();
  name = ui->lineEdit_1->text();
  opuc = ui->lineEdit_4->text();

  if (!conn.connOpen()) {
    qDebug() << "Not open";
    return;
  }

  conn.connOpen();
  //доступ до файлу
  QSqlQuery qry;
  //добавлення в файл
  qry.prepare("update challenge set Name='" + name + "', Description='" + opuc +
              "' where id='" + idn + "'");
  //дані де не NOT NULL, обов'язково заповнити
  if (qry.exec()) {
    QMessageBox::critical(this, tr("Edit"), tr("update"));
    conn.connClose();
  } else {
    QMessageBox::critical(this, tr("error::"), qry.lastError().text());
  }
}

//видалення даних
void EmplpyeeInfo::on_pushButton_3_clicked() {
  Login conn;
  QString name, opuc, idn;
  idn = ui->lineEdit->text();

  if (!conn.connOpen()) {
    qDebug() << "Not open";
    return;
  }

  conn.connOpen();
  //доступ до файлу
  QSqlQuery qry;
  //добавлення в файл
  qry.prepare("Delete from challenge where id='" + idn + "'");
  //дані де не NOT NULL, обов'язково заповнити
  if (qry.exec()) {
    QMessageBox::critical(this, tr("Delete"), tr("delete"));
    conn.connClose();
  } else {
    QMessageBox::critical(this, tr("error::"), qry.lastError().text());
  }
}

//вивід
void EmplpyeeInfo::on_pb_show_clicked() {
  //  Login conn;
  //  QSqlQueryModel *modal = new QSqlQueryModel();

  //  conn.connOpen();
  //  QSqlQuery *qry = new QSqlQuery(conn.mydb);

  //  qry->prepare("select * from challenge");
  //  qry->exec();
  //  modal->setQuery(*qry);
  //  ui->treeView->setModel(modal);

  //  conn.connClose();
  //  qDebug() << (modal->rowCount());
}
