#include "treeview.h"
#include "mycheckbox.h"
#include "qtreewidgetutil.h"
#include "ui_treeview.h"

#include <QSqlTableModel>
#include <QTreeWidgetItem>

TreeView::TreeView(QWidget *parent) : QDialog(parent), ui(new Ui::TreeView) {
    ui->setupUi(this);

    conn = DBManager::getInstance();
    conn->connectToDataBase();
    //Підключити базу даних, щоб висвітлювалась у дереві
    //таблиця challenge з'єднана з таблицею children по link (foreign key)

    QList<QTreeWidgetItem *> topItems;
    QList<Challenge> challengesList = conn->getChellengesList();
    for (Challenge challenge : challengesList) {
        qDebug() << challenge.getId();
        qDebug() << challenge.getName();
        qDebug() << challenge.getDescription();
    }
// TODO

//    for (QString str : *challengesList) {
//        QTreeWidgetItem *top = new QTreeWidgetItem({str});

//        QStringList *childrenList = new QStringList();
//        QList<QTreeWidgetItem *> children;
//        query.exec("SELECT " TABLE_NAME_1 ", " TABLE_LINK_1 " FROM " TABLE_1);
//        while (query.next()) {
//            *childrenList << query.value(0).toString();
//        }

//        for (QString strChild : *childrenList) {
//            children.append(new QTreeWidgetItem({strChild}));
//        }
//        top->addChildren(children);
//        topItems.append(top);
//    }

//    ui->treeWidget->addTopLevelItems(topItems);

//    const int n_tops = ui->treeWidget->topLevelItemCount();
//    for (int a = 0; a < n_tops; ++a) {
//        const int n_children = ui->treeWidget->topLevelItem(a)->childCount();
//        qtreewidgetitem_assign_qcheckbox(ui->treeWidget,
//                                         ui->treeWidget->topLevelItem(a));
//        for (int b = 0; b < n_children; ++b) {
//            qtreewidgetitem_assign_qcheckbox(
//                        ui->treeWidget, ui->treeWidget->topLevelItem(a)->child(b));
//        }
//    }
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

    //  DataBase conn;
    //  QStringList *mychallengesList = new QStringList();
    //  QVariantList data;

    // mychallengesList <<
    qtreewidget_traverse<TreeView *, MyCheckBox, ONLY_CHECKED_ITEM>(
                ui->treeWidget, this);

    // mychallengesList << qtreewidgetitem_traverse;
    //  data.append(*mychallengesList);
    //  conn.inserIntoTable(data);
}
