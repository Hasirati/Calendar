#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "userdata.h"
#include <QSqlDatabase>
#include <QDebug>
#include "gatheringinf.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pb_start_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    gatheringInf obj;
};
#endif // MAINWINDOW_H
