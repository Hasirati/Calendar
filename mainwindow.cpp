#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:/Shozda/course-Calendar-of-good-habits/DB.sqlite");
}

MainWindow::~MainWindow()
{
    delete ui;
}


//void MainWindow::on_pushButton_clicked()
//{
//    ui->comboBox->currentText();
//}

void MainWindow::on_pb_start_clicked()
{
    hide();
    obj.show();
}

