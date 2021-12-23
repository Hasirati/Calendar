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

void Adward::on_pb_choose_clicked() {
  int difference = 20;
  ui->lb_suma->setText(QString::number(difference));
}
