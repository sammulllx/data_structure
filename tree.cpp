#include "tree.h"
#include "ui_tree.h"
#include <iostream>
#include <stack>

using namespace std;

string tmp;
tree::tree(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tree)
{
    ui->setupUi(this);
}

tree::~tree()
{
    delete ui;
}




struct TreeNode{
    char element;
    TreeNode* leftChild;
    TreeNode* rightChild;
    TreeNode(char ch, TreeNode* l, TreeNode* r) {
        element = ch;
        leftChild = l;
        rightChild = r;
    }
    TreeNode() {
        element = '0';
        leftChild = 0;
        rightChild = 0;
    }
};

//测试函数——输出树
void drawTree(TreeNode* root, bool infix, int size) {
    if (infix) {
        if (root) {
            //中序遍历

            drawTree(root->leftChild, infix, size);
            cout << root->element;
            tmp.push_back(root->element);
            drawTree(root->rightChild, infix, size);

        }
        else return;
    }
    else {
        if (root) {
            //后序遍历
            drawTree(root->leftChild, infix, size);
            drawTree(root->rightChild, infix, size);
            cout << root->element;

        }
        else return;
    }
}


void tree::on_pushButton_2_clicked()
{
       ui->TBtree->clear();
       ui->TBtree->append("click tree");


        cout<<"start  tree converting ";
        stack<TreeNode> expressionTree;
        QString qinput = ui->LEtree->text();
        std::string input = qinput.toStdString();
        for(int j=0;j<1;j++)

       {

            if (input == "0") break;
            for (int i = input.size() - 1; i >= 0;) {
                char ch = input[i--];
                if (ch >= '0' && ch <= '9') {
                    TreeNode leaves;
                    leaves.element = ch;
                    expressionTree.push(leaves);
                }
                else {
                    //出栈，成为新结点右子树
                    TreeNode* right = new TreeNode(expressionTree.top().element, expressionTree.top().leftChild, expressionTree.top().rightChild);
                    expressionTree.pop();

                    ////出栈，成为新结点左子树
                    TreeNode* left = new TreeNode(expressionTree.top().element, expressionTree.top().leftChild, expressionTree.top().rightChild);
                    expressionTree.pop();

                    //新结点入栈
                    TreeNode leave(ch, left, right);
                    expressionTree.push(leave);
                }
            }
            TreeNode* root = &expressionTree.top();
            //cout << expressionTree.top().element<<endl;

            expressionTree.pop();
            cout << "其对应的中缀表达式为" << endl;
            ui->TBtree->append("Its corresponding infix expression value is");

            drawTree(root, true, input.size());
            ui->TBtree->append(QString::fromStdString(tmp));
            cout<<tmp;
            cout << endl;
        }


}
