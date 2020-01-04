#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:



    void on_pushButton_stack_clicked();


  //  void on_pushButton_quicksort_clicked();

    void on_pushButton_tree_clicked();

    void on_pushBotton_grape_clicked();



    void on_pushButton_sort_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
