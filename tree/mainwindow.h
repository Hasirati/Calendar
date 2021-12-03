#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QTreeWidget;
class QTreeWidgetItem;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

  virtual void process(QTreeWidget *tree_widget, QTreeWidgetItem *tree_item);
private slots:
  void on_pushButton_clicked();

private:
  Ui::MainWindow *ui;

  bool listwidget_exists_item(const QString &item) const;
};
#endif // MAINWINDOW_H
