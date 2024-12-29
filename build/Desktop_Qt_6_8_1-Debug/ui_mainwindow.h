/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *openAddWindow;
    QTableWidget *tableWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1110, 605);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        openAddWindow = new QPushButton(centralwidget);
        openAddWindow->setObjectName("openAddWindow");
        openAddWindow->setGeometry(QRect(980, 480, 41, 31));
        openAddWindow->setAutoFillBackground(true);
        openAddWindow->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #fff; /* Text color */\n"
"    border: 2px solid #555; /* Border color */\n"
"    border-radius: 100px; /* Make the button round */\n"
"    border-style: outset;\n"
"    background: #000\n"
"    padding: 10px 20px; /* Add some padding for better button size */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: 0.3, fx: 0.3, fy: 0.3,\n"
"        radius: 1.35, stop: 0 #bbb, stop: 1 #777\n"
"    ); /* Darker gray gradient on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background: qradialgradient(\n"
"        cx: 0.3, cy: 0.3, fx: 0.3, fy: 0.3,\n"
"        radius: 1.35, stop: 0 #aaa, stop: 1 #555\n"
"    ); /* Even darker gray when pressed */\n"
"}\n"
""));
        openAddWindow->setFlat(false);
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(180, 30, 761, 431));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1110, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        openAddWindow->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        openAddWindow->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Justification", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
