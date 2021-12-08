#ifndef TREEVIEW_H
#define TREEVIEW_H

#include <QDialog>
#include <QWidget>
#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QMessageBox>

class QTreeWidget;
class QTreeWidgetItem;

namespace Ui {
class TreeView;
}

class TreeView : public QDialog {
  Q_OBJECT

public:
  explicit TreeView(QWidget *parent = nullptr);
  ~TreeView();
      virtual void process(QTreeWidget *tree_widget, QTreeWidgetItem *tree_item);
    QSqlDatabase db;

private slots:
  void on_pb_further_clicked();

private:
  Ui::TreeView *ui;
    bool listwidget_exists_item(const QString &item) const;
};

#endif // TREEVIEW_H
