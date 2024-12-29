#include <QFile>
#include <QStandardPaths>
#include <QMessageBox>
#include <QTextStream>
#include <QListWidgetItem>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addmore.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , openAddWindow(nullptr)
{
    ui->setupUi(this);
    connect(ui->openAddWindow, &QPushButton::clicked, this, &MainWindow::on_openAddWindow_clicked);

    QFile file(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "\\compras.txt");

    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QMessageBox::information(0, "Error", file.errorString());
        return;
    }

    // QTextStream in(&file);
    // while (!in.atEnd()) {
    //     QString line = in.readLine();
    //     if (!line.isEmpty()) {
    //         QListWidgetItem* item = new QListWidgetItem(line, ui->listItems);
    //         ui->listItems->addItem(item);  // Use addItem instead of addItems
    //         item->setFlags(item->flags() | Qt::ItemIsEditable);
    //     }
    // }
}

MainWindow::~MainWindow()
{
    delete ui;

    // QFile file(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "\\compras.txt");
    // if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
    //     QMessageBox::information(0, "Error", file.errorString());
    //     return;
    // }

    // QTextStream out(&file);

    // for (int i = 0; i < ui->tableWidget->columnCount(); ++i) {
    //     out<<ui->listItems->item(i)->text()<<"\n";
    // }

}

void MainWindow::on_openAddWindow_clicked()
{
    if (openAddWindow == nullptr) {
        openAddWindow = new AddMore();
        connect(openAddWindow, &AddMore::textUpdated, this, &MainWindow::onTextReceived);
    }
    openAddWindow->show();
}

void MainWindow::onTextReceived(const QString &name, const QString &just)
{
    int rowCount = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(rowCount);

    ui->tableWidget->setItem(rowCount, 0, new QTableWidgetItem(name));
    ui->tableWidget->setItem(rowCount, 1, new QTableWidgetItem(just));

    QFile file(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "\\compras.txt");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << name << "\n";
        out << just << "\n";
    } else {
        QMessageBox::information(0, "Error", file.errorString());
    }
}
