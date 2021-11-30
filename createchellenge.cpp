#include "createchellenge.h"
#include "ui_createchellenge.h"

CreateChellenge::CreateChellenge(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateChellenge)
{
    ui->setupUi(this);
}

CreateChellenge::~CreateChellenge()
{
    delete ui;
}
