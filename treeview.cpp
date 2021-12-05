#include "treeview.h"
#include "dbmanager.h"
#include "ui_treeview.h"

TreeView::TreeView(QWidget *parent) : QDialog(parent), ui(new Ui::TreeView) {
  ui->setupUi(this);
}

TreeView::~TreeView() { delete ui; }

void TreeView::on_pb_further_clicked() {}
