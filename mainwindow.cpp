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

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        if (!line.isEmpty()) {
            QListWidgetItem* item = new QListWidgetItem(line, ui->listItems);
            ui->listItems->addItem(item);  // Use addItem instead of addItems
            item->setFlags(item->flags() | Qt::ItemIsEditable);
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;

    QFile file(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "\\compras.txt");
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QMessageBox::information(0, "Error", file.errorString());
        return;
    }

    QTextStream out(&file);

    for (int i = 0; i < ui->listItems->count(); ++i) {
        out<<ui->listItems->item(i)->text()<<"\n";
    }

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
    // Construct the item text with HTML formatting
    QString itemText = "<b>" + name + "</b><br>" + just;
    QListWidgetItem *item = new QListWidgetItem(itemText, ui->listItems);
    ui->listItems->addItem(item);  // Use addItem here as well
    item->setFlags(item->flags() | Qt::ItemIsEditable);

    // Save the new item to the file
    QFile file(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "\\compras.txt");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << itemText << "\n";
    } else {
        QMessageBox::information(0, "Error", file.errorString());
    }
}
