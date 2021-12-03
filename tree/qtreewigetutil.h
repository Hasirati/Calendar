#ifndef QTREEWIGETUTIL_H
#define QTREEWIGETUTIL_H

#include <QTreeWidget>
#include <QTreeWidgetItem>

#define FIRST_COLUMN 0 //!< перша колонка

enum MyTreeProcessingMode {
  ONLY_CHECKED_ITEM, //!< лише вибрані елементи
  ALL_ITEMS //!< всі елементи (вибрані та невибрані)
};

template <typename MyObject, typename WidgetType, int mode>
void qtreewidgetitem_traverse(QTreeWidget *tree_widget,
                              QTreeWidgetItem *tree_item, MyObject processor) {
  QTreeWidgetItem *child_item = nullptr;
  QWidget *item_widget = nullptr;
  WidgetType *widget = nullptr;

  //тут ми починаємо переглядати дочірні елементи кожного елемента (він може
  //бути верхнього рівня чи ні)
  if (tree_item->childCount() > 0) {
    const int n_child = tree_item->childCount();
    for (int a = 0; a < n_child; ++a) {
      child_item = tree_item->child(a);
      item_widget = tree_widget->itemWidget(child_item, FIRST_COLUMN);
      widget = static_cast<WidgetType *>(item_widget);
      if (mode == ALL_ITEMS) {
        processor->process(tree_widget, child_item);

        //тут ми рекурсивно проходимо дочірніх елементів елемента
        qtreewidgetitem_traverse<MyObject, WidgetType, mode>(
            tree_widget, child_item, processor);
      } else if (mode == ONLY_CHECKED_ITEM) {
        if (widget) {
          if (widget->isChecked()) {
            processor->process(tree_widget, child_item);

            //тут ми рекурсивно проходимо дочірніх елементів елемента
            qtreewidgetitem_traverse<MyObject, WidgetType, mode>(
                tree_widget, child_item, processor);
          }
        }
      }
    }
  } else {
    //тут у нього немає дітей, але ми можемо обробити його безпосередньо
    item_widget = tree_widget->itemWidget(tree_item, FIRST_COLUMN);
    widget = static_cast<WidgetType *>(item_widget);
    if (mode == ALL_ITEMS) {
      processor->process(tree_widget, tree_item);
    } else if (mode == ONLY_CHECKED_ITEM) {
      if (widget) {
        if (widget->isChecked()) {
          processor->process(tree_widget, tree_item);
        }
      }
    }
  }
}

template <typename MyObject, typename WidgetType, int mode>
void qtreewidget_traverse(QTreeWidget *tree_widget, MyObject processor) {
  QTreeWidgetItem *top_item = nullptr;
  //тут ми проходимо через елементи верхнього рівня, щоб пройти їх дочірній
  //елемент
  const int n_tops = tree_widget->topLevelItemCount();
  for (int a = 0; a < n_tops; ++a) {
    top_item = tree_widget->topLevelItem(a);

    //тут ми проходимо дочірніх елементів елемента верхнього рівня
    qtreewidgetitem_traverse<MyObject, WidgetType, mode>(tree_widget, top_item,
                                                         processor);
  }
}

void qtreewidgetitem_assign_qcheckbox(QTreeWidget *tree_widget,
                                      QTreeWidgetItem *tree_item);

#endif // QTREEWIGETUTIL_H
