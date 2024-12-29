#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardPaths>
#include "addmore.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_openAddWindow_clicked();
    void onTextReceived(const QString &name,const QString &just);

private:
    Ui::MainWindow *ui;
    AddMore *openAddWindow;
    QString path =QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "\\compras.txt";
};
#endif // MAINWINDOW_H
