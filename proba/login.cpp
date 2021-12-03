#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) : QMainWindow(parent), ui(new Ui::Login) {
  ui->setupUi(this);

  mydb = QSqlDatabase::addDatabase("QSQLITE");
  mydb.setDatabaseName(
      "D:/Shozda/course-Calendar-of-good-habits/DB.sqlite");

  //перевіряю чи відкриваю файл
  if (!connOpen())
    ui->label->setText("Not open");
  else
    ui->label->setText("Connected");
}

Login::~Login() { delete ui; }

void Login::on_pushButton_clicked() {
  //пароль
  QString username, password;
  username = ui->lineEdit_username->text();
  password = ui->lineEdit_Password->text();

  if (!connOpen()) {
    qDebug() << "Not open";
    return;
  }

  connOpen();
  //доступ до файлу
  QSqlQuery qry;
  qry.prepare("select * from challenge where username='" + username +
              "' and password='" + password + "'");
  //не працює, мало не дозволяти дальше рухатись
  //працює, якщо тип даних varchar
  if (qry.exec()) {
    int count = 0;
    while (qry.next()) {
      count++;
    }

    if (count == 1) {
      ui->label->setText("Righty");
      // mydb.connClose();
      connClose();
      this->hide();
      EmplpyeeInfo emplpyeeinfo;
      emplpyeeinfo.setModal(true);
      emplpyeeinfo.exec();
    }
    //при не правильному паролі
    else if (count > 1)
      ui->label->setText("rggga");
    else if (count < 1)
      ui->label->setText("lose");
  }
}
