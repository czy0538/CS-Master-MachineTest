#include <iostream>
#include <queue>
#include <string>
using namespace std;

using ElementType = char; //定义数据类型

//节点
struct BinaryTreeNode
{
    ElementType data; //数据
    BinaryTreeNode *lchild, *rchild;
    BinaryTreeNode(ElementType c) : data(c), lchild(nullptr), rchild(nullptr){}
};

//节点访问函数
ElementType visit(BinaryTreeNode *&node)
{
    if (node != nullptr)
    {
        return node->data;
    }
    return 0;
}

//PreOrder
void PreOrder(BinaryTreeNode *&node)
{
    if (node == nullptr)
        return;
    visit(node);
    PreOrder(node->lchild);
    PreOrder(node->rchild);
}

//InOrder
void InOrder(BinaryTreeNode *&node)
{
    if (node == nullptr)
        return;
    InOrder(node->lchild);
    visit(node);
    InOrder(node->rchild);
}

//PostOrder
BinaryTreeNode *PostOrder(BinaryTreeNode *&node)
{
    if (node == nullptr)
        return;
    PostOrder(node->lchild);
    PostOrder(node->rchild);
    visit(node);
}

//LevelOrder
void LevelOrder(BinaryTreeNode *&node)
{
    BinaryTreeNode *t;
    queue<BinaryTreeNode *> q;
    if (node = nullptr)
        return;
    q.push(node);
    while (!q.empty())
    {
        t = q.front();
        q.pop();
        visit(t);
        if (t->lchild != nullptr)
            q.push(t->lchild);
        if (t->rchild != nullptr)
            q.push(t->rchild);
    }
}

//creatTreePreOrder,不唯一
void creatTreePreOrder(BinaryTreeNode *&node, const string &str, int &pos)
{
    char c = str[pos++];
    //空树
    if (c == '#')
    {
        node = nullptr;
        return;
    }
    node = new BinaryTreeNode(c);
    creatTreePreOrder(node->lchild, str, pos);
    creatTreePreOrder(node->rchild, str, pos);
}

//根据先序和中序确定子树
BinaryTreeNode* creatTreePre_InOrade(string pre,string in)
{
    if(pre.size()==0)
        return nullptr;
    char c = pre[0];
    int pos = in.find(c);
    BinaryTreeNode *root = new BinaryTreeNode(c);
    root->lchild = creatTreePre_InOrade(pre.substr(1, pos), in.substr(0, pos));
    root->rchild = creatTreePre_InOrade(pre.substr(pos + 1), in.substr(pos + 1));
    return root;
}