#include "start.h"
#include "ui_start.h"
#include "dbmanager.h"

Start::Start(QWidget *parent) : QWidget(parent), ui(new Ui::Start) {
    ui->setupUi(this);
    QPixmap pix(PICTURE "start.jpg");
    ui->lb_pic->setPixmap(pix);
}

Start::~Start() { delete ui; }

void Start::on_pb_start_clicked() {
    hide();
    obj.show();
}
