#ifndef TREEVIEW_H
#define TREEVIEW_H

#include <QDialog>
#include <QTreeView>
#include <QWidget>

namespace Ui {
class TreeView;
}

class TreeView : public QDialog {
  Q_OBJECT

public:
  explicit TreeView(QWidget *parent = nullptr);
  ~TreeView();

private slots:
  void on_pb_further_clicked();

private:
  Ui::TreeView *ui;
};

#endif // TREEVIEW_H
