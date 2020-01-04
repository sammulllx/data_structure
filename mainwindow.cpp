#include "winstack.h"
#include "mainwindow.h"
#include "tree.h"
#include "quicksort.h"
#include "graph.h"

#include "ui_mainwindow.h"
#include <iostream>

#include <stack>//使用标准库里面的栈
#include <cstring>
#include <string>




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



//tree




//quicksort




void MainWindow::on_pushButton_stack_clicked()
{
    winstack *win = new winstack();
    win->show();



}

//void MainWindow::on_pushButton_quicksort_clicked()
//{
//    quicksort *qu = new quicksort();
//    qu->show();
//}

void MainWindow::on_pushButton_tree_clicked()
{
    tree *tr = new tree();
    tr->show();

}

void MainWindow::on_pushBotton_grape_clicked()
{
    graph *gr = new graph();
    gr->show();

}



void MainWindow::on_pushButton_sort_clicked()
{
    quicksort *qu = new quicksort();
    qu->show();
}
