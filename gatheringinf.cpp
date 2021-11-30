#include "gatheringinf.h"
#include "ui_gatheringinf.h"

gatheringInf::gatheringInf(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gatheringInf)
{
    ui->setupUi(this);
}

gatheringInf::~gatheringInf()
{
    delete ui;
}
