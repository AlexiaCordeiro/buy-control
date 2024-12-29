#ifndef ADDMORE_H
#define ADDMORE_H

#include <QWidget>

namespace Ui {
class AddMore;
}

class AddMore : public QWidget
{
    Q_OBJECT

public:
    explicit AddMore(QWidget *parent = nullptr);
    ~AddMore();
signals:
    void textUpdated(const QString &name, const QString &just);

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddMore *ui;
    void displayContent(const QString &name, const QString &just);
};

#endif // ADDMORE_H
