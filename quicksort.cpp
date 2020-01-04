#include "quicksort.h"
#include <QApplication>
#include "ui_quicksort.h"
#include <iostream>

using namespace std;
int data_size = 12;//数组里元素的个数

quicksort::quicksort(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::quicksort)
{
    ui->setupUi(this);
}

quicksort::~quicksort()
{
    delete ui;
}


template<class T>
void quicksort1(T data[], int first, int last){
    int lower = first + 1, upper = last;   //定义上下界
    if (data[first] < data[(first + last) / 2])   //判断第一个和中间的数据的大小
        swap(data[first], data[(first + last) / 2]);    // 第一个数据与中间数据进行交换
    T bound = data[first];//设置边界值
    while (lower <= upper){
        while (data[lower] < bound)
            lower++;
        while (bound < data[upper])
            upper--;
        if (lower < upper)
            swap(data[lower++], data[upper--]);
        else lower++;
    }
    swap(data[upper], data[first]);
    if (first < upper - 1)
        quicksort1(data, first, upper - 1);
    if (upper + 1 < last)
        quicksort1(data, upper + 1, last);

}

template<class T>
void quicksort1(T data[], int n){
    int max, i;
    if (n < 2)
        return;
    for (i = 1, max = 0; i < n; i++)//找最大值
        if (data[max]<data[i])
            max = i;
    swap(data[n - 1], data[max]);
    quicksort1(data, 0, n - 2);
}


//随机选择一个值进行
template<class T>
void randquicksort(T data[], int first, int last){
    int lower = first + 1, upper = last;   //定义上下界
    //if(data[first] < data[(first + last ) / 2])   //判断第一个和中间的数据的大小
    //swap(data[first],data[(first + last ) / 2]);    // 第一个数据与中间数据进行交换
    swap(data[first], data[rand() % data_size]); //将边界值设置为随机一个元素
    T bound = data[first];//设置边界值
    while (lower <= upper){
        while (data[lower] < bound)
            lower++;
        while (bound < data[upper])
            upper--;
        if (lower < upper)
            swap(data[lower++], data[upper--]);
        else lower++;
    }
    swap(data[upper], data[first]);
    if (first < upper - 1)
        quicksort1(data, first, upper - 1);
    if (upper + 1 < last)
        quicksort1(data, upper + 1, last);

}

template<class T>
void randquicksort(T data[], int n){
    int max, i;
    if (n < 2)
        return;
    for (i = 1, max = 0; i < n; i++)//找最大值
        if (data[max]<data[i])
            max = i;
    swap(data[n - 1], data[max]);
    quicksort1(data, 0, n - 2);
}

void quicksort::on_PBrank_clicked()
{
        int data1[] = { 6, 9, 5, 3, 2, 1, 7, 8, 9, 20, 13, 11 };
        int data2[] = { 6, 9, 5, 3, 2, 1, 7, 8, 9, 20, 13, 11 };
        int count_num;
        int length1 = sizeof(data1) / sizeof(data1[0]);
        ui->Tbrank->append("Complete the first phase:");
        for (count_num = 0; count_num < length1; count_num++)
        {
            cout << data1[count_num] << " ";
            ui->Tbrank->insertPlainText(QString::number(data1[count_num], 10));
            ui->Tbrank->moveCursor(QTextCursor::End);

        }

        cout << "完成二阶段" << endl;
        ui->Tbrank->append("Complete the second phase:");


        //书上的快排
        clock_t start, finish;
        start = clock();

        quicksort1<int>(data1, 0, length1 - 1);
        finish = clock();

        cout << finish - start << "/" << CLOCKS_PER_SEC << " (s) " << endl;

        for (count_num = 0; count_num < length1; count_num++)
        {
            cout << data1[count_num] << " ";
           // ui->Tbrank->append(QString::number(data1[count_num], 10));
            ui->Tbrank->insertPlainText(QString::number(data1[count_num], 10));
            ui->Tbrank->moveCursor(QTextCursor::End);

        }
        cout << "完成三阶段" << endl;
        ui->Tbrank->append("Complete the three phase:");

        //随机快速排序
        clock_t start1, finish1;
        start1 = clock();

        randquicksort<int>(data2, 0, 11);

        finish1 = clock();

        cout << finish1 - start1 << "/" << CLOCKS_PER_SEC << " (s) " << endl;
        //randquicksort<int> (data2,0,11) ;
        for (count_num = 0; count_num < 12; count_num++)
        {
            cout << data2[count_num] << " ";
           // ui->Tbrank->append(QString::number(data2[count_num], 10));
            ui->Tbrank->insertPlainText(QString::number(data2[count_num], 10));
            ui->Tbrank->moveCursor(QTextCursor::End);
        }

}











