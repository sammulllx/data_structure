#ifndef WINSTACK_H
#define WINSTACK_H

#include <QWidget>

namespace Ui {
class winstack;
}

class winstack : public QWidget
{
    Q_OBJECT

public:
    explicit winstack(QWidget *parent = 0);
    ~winstack();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::winstack *ui;
};

#endif // WINSTACK_H
