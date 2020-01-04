#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <QWidget>

namespace Ui {
class quicksort;
}

class quicksort : public QWidget
{
    Q_OBJECT

public:
    explicit quicksort(QWidget *parent = 0);
    ~quicksort();

private slots:
    void on_PBrank_clicked();

private:
    Ui::quicksort *ui;
};

#endif // QUICKSORT_H
