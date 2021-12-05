/********************************************************************************
** Form generated from reading UI file 'emplpyeeinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLPYEEINFO_H
#define UI_EMPLPYEEINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_EmplpyeeInfo
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton_2;
    QLabel *label_3;
    QPushButton *pushButton_3;
    QFormLayout *formLayout;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_1;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QPushButton *pb_show;
    QTableView *tableView;
    QPushButton *pushButton;

    void setupUi(QDialog *EmplpyeeInfo)
    {
        if (EmplpyeeInfo->objectName().isEmpty())
            EmplpyeeInfo->setObjectName(QString::fromUtf8("EmplpyeeInfo"));
        EmplpyeeInfo->resize(696, 507);
        gridLayout = new QGridLayout(EmplpyeeInfo);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_2 = new QPushButton(EmplpyeeInfo);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 2, 0, 1, 1);

        label_3 = new QLabel(EmplpyeeInfo);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 7, 0, 1, 1);

        pushButton_3 = new QPushButton(EmplpyeeInfo);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 4, 0, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        lineEdit_4 = new QLineEdit(EmplpyeeInfo);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_4);

        lineEdit_1 = new QLineEdit(EmplpyeeInfo);
        lineEdit_1->setObjectName(QString::fromUtf8("lineEdit_1"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_1);

        label_2 = new QLabel(EmplpyeeInfo);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label = new QLabel(EmplpyeeInfo);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label);

        label_4 = new QLabel(EmplpyeeInfo);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_4);

        lineEdit = new QLineEdit(EmplpyeeInfo);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);


        gridLayout->addLayout(formLayout, 0, 0, 1, 2);

        pb_show = new QPushButton(EmplpyeeInfo);
        pb_show->setObjectName(QString::fromUtf8("pb_show"));

        gridLayout->addWidget(pb_show, 5, 0, 1, 1);

        tableView = new QTableView(EmplpyeeInfo);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 6, 0, 1, 1);

        pushButton = new QPushButton(EmplpyeeInfo);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 3, 0, 1, 1);


        retranslateUi(EmplpyeeInfo);

        QMetaObject::connectSlotsByName(EmplpyeeInfo);
    } // setupUi

    void retranslateUi(QDialog *EmplpyeeInfo)
    {
        EmplpyeeInfo->setWindowTitle(QApplication::translate("EmplpyeeInfo", "Dialog", nullptr));
        pushButton_2->setText(QApplication::translate("EmplpyeeInfo", "UPDATE", nullptr));
        label_3->setText(QApplication::translate("EmplpyeeInfo", "TextLabel", nullptr));
        pushButton_3->setText(QApplication::translate("EmplpyeeInfo", "DELETE", nullptr));
        label_2->setText(QApplication::translate("EmplpyeeInfo", "Name", nullptr));
        label->setText(QApplication::translate("EmplpyeeInfo", "pass", nullptr));
        label_4->setText(QApplication::translate("EmplpyeeInfo", "id", nullptr));
        pb_show->setText(QApplication::translate("EmplpyeeInfo", "Show", nullptr));
        pushButton->setText(QApplication::translate("EmplpyeeInfo", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EmplpyeeInfo: public Ui_EmplpyeeInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLPYEEINFO_H
