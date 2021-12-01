#include "start.h"
#include "ui_start.h"

Start::Start(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Start)
{
    ui->setupUi(this);
}

Start::~Start()
{
    delete ui;
}

void Start::on_pb_start_clicked()
{
    hide();
    obj.show();
}

