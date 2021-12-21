#ifndef CHECKBOX_H
#define CHECKBOX_H
#include <QCheckBox>

class QTreeWidgetItem;

class MyCheckBox : public QCheckBox {
    Q_OBJECT
public:
    MyCheckBox(QTreeWidgetItem *item);
    QTreeWidgetItem *tree_item() const { return m_tree_item; }
    QTreeWidgetItem *m_tree_item;

    void set_children_checked_unchecked(QTreeWidgetItem *my_item) const;
    void set_parent_checked(QTreeWidgetItem *my_tree_item) const;
    void
    set_parent_checked_unchecked_based_on_siblings(MyCheckBox *my_checkbox) const;
};

#endif // CHECKBOX_H
