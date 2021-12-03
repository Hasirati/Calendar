#ifndef EMPLPYEEINFO_H
#define EMPLPYEEINFO_H

#include "login.h"
#include <QDialog>
#include <QFile>

#include <QMessageBox>

namespace Ui {
class EmplpyeeInfo;
}

class EmplpyeeInfo : public QDialog {
  Q_OBJECT

public:
  explicit EmplpyeeInfo(QWidget *parent = nullptr);
  ~EmplpyeeInfo();

private slots:
  void on_pushButton_clicked();

  void on_pushButton_2_clicked();

  void on_pushButton_3_clicked();

  void on_pb_show_clicked();

private:
  Ui::EmplpyeeInfo *ui;
};

#endif // EMPLPYEEINFO_H
