#include "adward.h"
#include "ui_adward.h"

Adward::Adward(QWidget *parent) : QDialog(parent), ui(new Ui::Adward) {
  ui->setupUi(this);

  QSqlTableModel *model = new QSqlTableModel();
  model->setTable(TABLE_3);
  ui->tableView->setModel(model);
  model->select();
  qDebug() << (model->rowCount());

  ui->lb_suma->setText(QString::number(sum));
}

Adward::~Adward() { delete ui; }

void Adward::counts() {
  //підраховує бали за виконані завдання
  int *sum = 0;
}

void Adward::on_pushButton_clicked() {
  //знімає бали з рахунку
  int difference = 0;
  ui->lb_suma->setText(QString::number(difference));
}
