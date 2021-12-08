#include "treeview.h"
#include "dbmanager.h"
#include "ui_treeview.h"
#include <QTreeWidgetItem>
#include <QSqlTableModel>
#include "mycheckbox.h"
#include "qtreewidgetutil.h"

TreeView::TreeView(QWidget *parent) : QDialog(parent), ui(new Ui::TreeView) {
  ui->setupUi(this);

    DataBase conn;
    conn.connectToDataBase();

  QStringList *challengesList = new QStringList(); //{"popular habits","stay at home","most importantly"};  // отримати з БД
      QList<QTreeWidgetItem *> topItems;
      //challengesList->setTable("challenge");


      for (QString str: *challengesList) {
          QTreeWidgetItem *top = new QTreeWidgetItem({str});

          QStringList *childrenList = new QStringList(); //{"Read", "Learn a foreign language", "Brush your teeth"}; //Отримати з бази даних для id = str

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
