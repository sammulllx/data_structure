#ifndef TREE_H
#define TREE_H

#include <QWidget>

namespace Ui {
class tree;
}

class tree : public QWidget
{
    Q_OBJECT

public:
    explicit tree(QWidget *parent = 0);
    ~tree();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::tree *ui;
};

#endif // TREE_H
