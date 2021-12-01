#include "createchellenge.h"
#include "mainwindow.h"
#include "ui_createchellenge.h"

CreateChellenge::CreateChellenge(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateChellenge)
{
    ui->setupUi(this);
    ui->lineEdit->close();
}

CreateChellenge::~CreateChellenge()
{
    delete ui;
}

void CreateChellenge::on_pb_water_clicked()
{
    ui->pb_read->close();
    ui->pb_train->close();
    ui->pb_water->close();
    ui->pb_walk->close();
    ui->label->setText("How many \nglasses a day?");
    hide();
    obj.show();

}


void CreateChellenge::on_pb_walk_clicked()
{
    ui->pb_read->close();
    ui->pb_train->close();
    ui->pb_water->close();
    ui->pb_walk->close();
    ui->label->setText("How many \nkilometers?");
    hide();
    obj.show();
}


void CreateChellenge::on_pb_train_clicked()
{
    ui->pb_read->close();
    ui->pb_train->close();
    ui->pb_water->close();
    ui->pb_walk->close();
    ui->label->setText("How much \ntime at a time?");
    hide();
    obj.show();
}


void CreateChellenge::on_pb_read_clicked()
{
    ui->pb_read->close();
    ui->pb_train->close();
    ui->pb_water->close();
    ui->pb_walk->close();
    ui->label->setText("How many \npages a day?");
    hide();
    obj.show();

}

