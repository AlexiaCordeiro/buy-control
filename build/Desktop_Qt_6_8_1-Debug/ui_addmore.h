/********************************************************************************
** Form generated from reading UI file 'addmore.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDMORE_H
#define UI_ADDMORE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddMore
{
public:
    QPushButton *pushButton;
    QTextEdit *justIn;
    QLineEdit *nameIn;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *AddMore)
    {
        if (AddMore->objectName().isEmpty())
            AddMore->setObjectName("AddMore");
        AddMore->resize(842, 485);
        pushButton = new QPushButton(AddMore);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(640, 160, 80, 25));
        justIn = new QTextEdit(AddMore);
        justIn->setObjectName("justIn");
        justIn->setGeometry(QRect(140, 190, 104, 70));
        nameIn = new QLineEdit(AddMore);
        nameIn->setObjectName("nameIn");
        nameIn->setGeometry(QRect(150, 110, 113, 25));
        label = new QLabel(AddMore);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 110, 54, 17));
        label_2 = new QLabel(AddMore);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 190, 54, 17));

        retranslateUi(AddMore);

        QMetaObject::connectSlotsByName(AddMore);
    } // setupUi

    void retranslateUi(QWidget *AddMore)
    {
        AddMore->setWindowTitle(QCoreApplication::translate("AddMore", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("AddMore", "PushButton", nullptr));
        label->setText(QCoreApplication::translate("AddMore", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("AddMore", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddMore: public Ui_AddMore {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDMORE_H
