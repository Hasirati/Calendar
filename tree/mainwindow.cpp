#include "mainwindow.h"
#include "mycheckbox.h"
#include "qtreewigetutil.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  QTreeWidgetItem *top1 = new QTreeWidgetItem({"Grupa 1"});
  QTreeWidgetItem *top2 = new QTreeWidgetItem({"Grupa 2"});
  QTreeWidgetItem *top3 = new QTreeWidgetItem({"Grupa 3"});

  QList<QTreeWidgetItem *> children1;
  QList<QTreeWidgetItem *> children2;
  QList<QTreeWidgetItem *> children3;

  children1.append(new QTreeWidgetItem({"Rojo"}));
  children1.append(new QTreeWidgetItem({"Amarillo"}));
  children1.append(new QTreeWidgetItem({"Azul"}));

  children2.append(new QTreeWidgetItem({"Gris"}));
  children2.append(new QTreeWidgetItem({"Magenta"}));
  children2.append(new QTreeWidgetItem({"Cian"}));

  children3.append(new QTreeWidgetItem({"Naranja"}));
  children3.append(new QTreeWidgetItem({"Negro"}));
  children3.append(new QTreeWidgetItem({"Blanco"}));
  children3.append(new QTreeWidgetItem({"Verde"}));

  top1->addChildren(children1);
  top2->addChildren(children2);
  top3->addChildren(children3);

  ui->treeWidget->addTopLevelItems({top1, top2, top3});

  const int n_tops = ui->treeWidget->topLevelItemCount();
  for (int a = 0; a < n_tops; ++a) {
    const int n_children = ui->treeWidget->topLevelItem(a)->childCount();
    qtreewidgetitem_assign_qcheckbox(ui->treeWidget,
                                     ui->treeWidget->topLevelItem(a));
    for (int b = 0; b < n_children; ++b) {
      qtreewidgetitem_assign_qcheckbox(
          ui->treeWidget, ui->treeWidget->topLevelItem(a)->child(b));
    }
  }
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::process(QTreeWidget *tree_widget, QTreeWidgetItem *tree_item) {
  MyCheckBox *checkbox = static_cast<MyCheckBox *>(
      tree_widget->itemWidget(tree_item, FIRST_COLUMN));
  if (!listwidget_exists_item(checkbox->text())) {
    ui->listWidget->addItem(checkbox->text());
  }
}

void MainWindow::on_pushButton_clicked() {
  ui->listWidget->clear();

  qtreewidget_traverse<MainWindow *, MyCheckBox, ONLY_CHECKED_ITEM>(
      ui->treeWidget, this);
}

bool MainWindow::listwidget_exists_item(const QString &item) const {
  const int n_items = ui->listWidget->count();
  for (int a = 0; a < n_items; ++a) {
    if (ui->listWidget->item(a)->text() == item)
      return true;
  }
  return false;
}
