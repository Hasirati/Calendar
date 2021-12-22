#ifndef TREEVIEW_H
#define TREEVIEW_H

#include <QDialog>
#include <QFileInfo>
#include <QMainWindow>
#include <QMessageBox>
#include <QWidget>
#include <QtDebug>
#include <QtSql>

#include "dbmanager.h"

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

private slots:
  void on_pb_further_clicked();

private:
  Ui::TreeView *ui;
  DBManager *conn;
  QList<Challenge> challengesList;
  QMultiMap<int, Children *> childrensMultiMap;
  bool listwidget_exists_item(const QString &item) const;
};

#endif // TREEVIEW_H
