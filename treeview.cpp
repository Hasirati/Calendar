#include "treeview.h"
#include "challenge.h"
#include "children.h"
#include "mycheckbox.h"
#include "qtreewidgetutil.h"
#include "ui_treeview.h"

#include <QMultiMap>
#include <QSqlTableModel>
#include <QTreeWidgetItem>

TreeView::TreeView(QWidget *parent) : QDialog(parent), ui(new Ui::TreeView) {
  ui->setupUi(this);

  conn = DBManager::getInstance();
  conn->connectToDataBase();

  challengesList = conn->getChellengesList();
  childrensMultiMap = conn->getChildrensMap();

  for (Challenge challenge : challengesList) {
    QTreeWidgetItem *treeItem = new QTreeWidgetItem(ui->treeWidget);
    treeItem->setText(0, challenge.getName());
    for (auto children : childrensMultiMap.values(challenge.getId())) {
      QTreeWidgetItem *treeChildItem = new QTreeWidgetItem();
      treeChildItem->setText(0, children->getName());
      treeItem->addChild(treeChildItem);
    }
  }

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

TreeView::~TreeView() { delete ui; }

void TreeView::process(QTreeWidget *tree_widget, QTreeWidgetItem *tree_item) {
  MyCheckBox *checkbox = static_cast<MyCheckBox *>(
      tree_widget->itemWidget(tree_item, FIRST_COLUMN));
  if (!listwidget_exists_item(checkbox->text())) {
    ui->listWidget->addItem(checkbox->text());
  }
}

bool TreeView::listwidget_exists_item(const QString &item) const {
  const int n_items = ui->listWidget->count();
  for (int a = 0; a < n_items; ++a) {
    if (ui->listWidget->item(a)->text() == item)
      return true;
  }
  return false;
}

//дані які вибрали мають записуватись в MyChallenge
void TreeView::on_pb_further_clicked() {
  ui->listWidget->clear();

  qtreewidget_traverse<TreeView *, MyCheckBox, ONLY_CHECKED_ITEM>(
      ui->treeWidget, this);

  for (int i = 0; i < ui->listWidget->count(); i++) {
    Children *children =
        conn->getChildrenByName(ui->listWidget->item(i)->text());
    conn->saveToMyChellenge(children);
  }
}
