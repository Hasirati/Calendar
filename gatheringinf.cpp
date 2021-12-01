#include "gatheringinf.h"
#include "ui_gatheringinf.h"

gatheringInf::gatheringInf(QWidget *parent) :
    QWidget(parent), ui(new Ui::gatheringInf)
{ui->setupUi(this);}

gatheringInf::gatheringInf() {
    HOUR = 0;
    MINUTE = 0;
}

gatheringInf::~gatheringInf(){delete ui;}

void gatheringInf::on_pb_next_clicked()
{
//    ui->timeWakeUp->currentText();
      HOUR = ui->  timeWakeUp->time().hour();
      MINUTE = ui->   timeWakeUp->time().minute();
//      QString str = QString::number(HOUR) + QString::number(MINUTE);
//      ui->lb_question->setText(str);
}

void gatheringInf::getSelfControl() {
    cout << "Do you often put off things for later?\n";
    answer y = Yes;
    switch(y)
    {
        case Yes: cout << "\n";   break;
        case No : cout << "\n"; break;
    }
}
