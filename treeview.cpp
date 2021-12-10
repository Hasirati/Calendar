#include "treeview.h"
#include "dbmanager.h"
#include "mycheckbox.h"
#include "qtreewidgetutil.h"
#include "ui_treeview.h"
#include <QSqlTableModel>
#include <QTreeWidgetItem>

TreeView::TreeView(QWidget *parent) : QDialog(parent), ui(new Ui::TreeView) {
  ui->setupUi(this);

  DataBase conn;
  conn.connectToDataBase();
  //Підключити базу даних, щоб висвітлювалась у дереві
  //таблиця challenge з'єднана з таблицею children по link (foreign key)

  QStringList *challengesList = new QStringList();
  QList<QTreeWidgetItem *> topItems;
  // challengesList->setTable("challenge");

  for (QString str : *challengesList) {
    QTreeWidgetItem *top = new QTreeWidgetItem({str});

    QStringList *childrenList =
        new QStringList(); //Отримати з бази даних для id = str

    QList<QTreeWidgetItem *> children;

    for (QString strChild : *childrenList) {
      children.append(new QTreeWidgetItem({strChild}));
    }
    top->addChildren(children);

    topItems.append(top);
  }

  ui->treeWidget->addTopLevelItems(topItems);

  //      QSqlQueryModel *model = new QSqlQueryModel();

  //      QSqlQuery *qry = new QSqlQuery(db);

  //              qry->prepare("select * from" TABLE_2);
  //              qry->exec();
  //              model->setQuery(*qry);
  //              ui->treeWidget->addTopLevelItems({model});

  //статичні зміни - мають бути динамічні
  QTreeWidgetItem *top1 = new QTreeWidgetItem({"Popular habits"});
  QTreeWidgetItem *top2 = new QTreeWidgetItem({"Stay at home"});
  QTreeWidgetItem *top3 = new QTreeWidgetItem({"Most importantly"});

  QList<QTreeWidgetItem *> children1;
  QList<QTreeWidgetItem *> children2;
  QList<QTreeWidgetItem *> children3;

  children1.append(new QTreeWidgetItem({"Learn a foreign language"}));
  children1.append(new QTreeWidgetItem({"Drink water"}));
  children1.append(new QTreeWidgetItem({"Make the beds"}));

  children2.append(new QTreeWidgetItem({"Read"}));

  children3.append(new QTreeWidgetItem({"Brush your teeth"}));
  children3.append(new QTreeWidgetItem({"Train"}));
  children3.append(new QTreeWidgetItem({"Wash your hands regularly"}));

  top1->addChildren(children1);
  top2->addChildren(children2);
  top3->addChildren(children3);

  //дані які вибрали мають записуватись в MyChallenge
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

void TreeView::on_pb_further_clicked() {
  ui->listWidget->clear();

  qtreewidget_traverse<TreeView *, MyCheckBox, ONLY_CHECKED_ITEM>(
      ui->treeWidget, this);
}
