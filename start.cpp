#include "start.h"
#include "ui_start.h"

Start::Start(QWidget *parent) : QWidget(parent), ui(new Ui::Start) {
  ui->setupUi(this);
  QPixmap pix("D:/JULIA/OOP/course/course-Calendar-of-good-habits/"
              "picture/start.jpg");
  ui->lb_pic->setPixmap(pix);
}

Start::~Start() { delete ui; }

void Start::on_pb_start_clicked() {
  hide();
  obj.show();
}
