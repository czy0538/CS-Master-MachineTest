#include <string>
#include <iostream>
using namespace std;
struct Node
{
    char data;
    Node *left, *right;
    Node(char c) : data(c), left(nullptr), right(nullptr){};
};

Node *buildTree(string in, string pre)
{
    if (in.size() == 0)
        return nullptr;
    char c = pre[0];
    int pos = in.find(c);
    Node *node = new Node(c);
    node->left = buildTree(in.substr(0, pos), pre.substr(1, pos));
    node->right = buildTree(in.substr(pos + 1), pre.substr(pos+1));
    return node;
}

void PostOrder(Node* &node)
{
    if (node == nullptr)
        return;
    PostOrder(node->left);
    PostOrder(node->right);
    cout << node->data;
}

int main()
{
    string str1, str2;
    while(cin>>str1>>str2)
    {
        Node *root = buildTree(str2, str1);
        PostOrder(root);
        cout << endl;
    }
    return 0;
}
