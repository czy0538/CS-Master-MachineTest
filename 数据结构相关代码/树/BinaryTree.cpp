#include <iostream>
#include<queue>
#include<string>
using namespace std;

using ElementType = char; //定义数据类型

//节点
typedef struct BinaryTreeNode
{
    ElementType data; //数据
    BinaryTreeNode *lchild, *rchild;
} * BiTNode;

//节点访问函数
ElementType visit(BiTNode &node)
{
    if (node != nullptr)
    {
        return node->data;
    }
    return 0;
}

//PreOrder
void PreOrder(BiTNode &node)
{
    if (node == nullptr)
        return;
    visit(node);
    PreOrder(node->lchild);
    PreOrder(node->rchild);
}

//InOrder
void InOrder(BiTNode &node)
{
    if (node == nullptr)
        return;
    InOrder(node->lchild);
    visit(node);
    InOrder(node->rchild);
}

//PostOrder
BiTNode PostOrder(BiTNode &node)
{
    if (node == nullptr)
        return;
    PostOrder(node->lchild);
    PostOrder(node->rchild);
    visit(node);
}

//LevelOrder
void LevelOrder(BiTNode &node)
{
    BiTNode t;
    queue<BiTNode> q;
    if(node=nullptr)
        return;
    q.push(node);
    while(!q.empty())
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

//creatTreePreOrder
void creatTreePreOrder(BiTNode &node,const string &str,int &pos)
{

    //空树
    if(str[pos]=='#')
    {
        node = nullptr;
        return;
    }
    node = new BinaryTreeNode;
    node->data = str[pos++];
    creatTreePreOrder(node->lchild, str, pos);
    creatTreePreOrder(node->rchild, str, pos);
}