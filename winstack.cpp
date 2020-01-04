#include "winstack.h"
#include "ui_winstack.h"
#include "mainwindow.h"
#include <QApplication>
#include <iostream>

#include <stack>//使用标准库里面的栈
#include <cstring>
#include <string>
using namespace std;



winstack::winstack(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::winstack)
{
    ui->setupUi(this);
}

winstack::~winstack()
{
    delete ui;
}

void winstack::on_pushButton_clicked() //点击判断是否是回文
{
    ui->TBstack->clear(); // 初始化清空文本框
    QString posttemp;

    QString ifshow;
    QString temp = ui->LEstack->text();
    std::string temp1 = temp.toStdString();
    ui->TBstack->append("输入为："+temp);
    const char *ss = temp1.c_str();//将string转换成char*
    int len = temp1.size();
    cout<<len;
    stack <char> text;
    stack <char> text1;
    stack <char> text2;
    int i = 0;
    while (len--) {//入栈
        text.push(ss[i++]);
    }
    text1 = text;
    cout << "倒过看就来是"<<endl;
    while (!text1.empty()){
        int i = 0;
        posttemp.push_back(text1.top());
        cout << text1.top();
        text2.push(text1.top());
        text1.pop();
        i++;
    }
    cout<<endl;
    while (!text2.empty()){			//打印text2

        if (text.top() != text2.top()){
            ifshow = "判断结果：不是回文";

            break;
        }
        ifshow = "判断结果：是回文";

        break;
        text.pop();
        text2.pop();
    }

    ui->TBstack->append("倒过来是"+posttemp);
    ui->TBstack->append(ifshow);
}

void winstack::on_pushButton_2_clicked()
{
    cout<<"closed window successfully"<<endl;
    this->close();

}
