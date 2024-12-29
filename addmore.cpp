#include "addmore.h"
#include "ui_addmore.h"

AddMore::AddMore(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AddMore)
{
    ui->setupUi(this);
}

AddMore::~AddMore()
{
    delete ui;
}

QString name, just;

void AddMore::on_pushButton_clicked()
{
    name = ui->nameIn->text();
    just = ui->justIn->toPlainText();

    displayContent(name, just);

}

void AddMore::displayContent(const QString &name, const QString &just) {
    emit textUpdated(name, just);
    ui->nameIn->clear();
    ui->justIn->clear();
    ui->nameIn->setFocus();
    ui->justIn->setFocus();


    this->close();
}
