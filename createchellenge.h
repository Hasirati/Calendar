#ifndef CREATECHELLENGE_H
#define CREATECHELLENGE_H

#include "mainwindow.h"
#include <QWidget>

namespace Ui {
class CreateChellenge;
}

class CreateChellenge : public QWidget {
    Q_OBJECT

public:
    explicit CreateChellenge(QWidget *parent = nullptr);
    ~CreateChellenge();

private slots:
    void on_pb_water_clicked();
    void on_pb_walk_clicked();
    void on_pb_train_clicked();
    void on_pb_read_clicked();

private:
    Ui::CreateChellenge *ui;
    MainWindow obj;
    DBManager *conn;
};

#endif // CREATECHELLENGE_H
