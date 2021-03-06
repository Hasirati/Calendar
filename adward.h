#ifndef ADWARD_H
#define ADWARD_H

#include "dbmanager.h"
#include <QDialog>
#include <QSqlTableModel>

namespace Ui {
class Adward;
}

class Adward : public QDialog {
  Q_OBJECT
  int sum = 120;

public:
  explicit Adward(QWidget *parent = nullptr);
  ~Adward();

private slots:

  void on_pb_choose_clicked();

private:
  Ui::Adward *ui;
};

#endif // ADWARD_H
