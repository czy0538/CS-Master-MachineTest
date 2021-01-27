#include<iostream>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *leftChild;
    TreeNode *rightChild;
    TreeNode(int num):data(num),leftChild(NULL),rightChild(NULL) {};
};

TreeNode* Insert(TreeNode*root,int data) {
    if(root==NULL) {
        //�����½ڵ�
        root=new TreeNode(data);
    } else if(data<root->data) {
        //����������
        root->leftChild=Insert(root->leftChild,data);
    } else if(data>root->data)  {
        //����������
        root->rightChild=Insert(root->rightChild,data);
    }
    return root;
}

//ǰ�����
void PreOrder(TreeNode *root) {
    if(root==NULL)return;
    printf("%d ",root->data);
    PreOrder(root->leftChild);
    PreOrder(root->rightChild);
    return;
}

//�������
void InOrder(TreeNode *root) {
    if(root==NULL)return;
    InOrder(root->leftChild);
    printf("%d ",root->data);
    InOrder(root->rightChild);
    return;
}

//�������
void PostOrder(TreeNode *root) {
    if(root==NULL)return;
    PostOrder(root->leftChild);
    PostOrder(root->rightChild);
    printf("%d ",root->data);
    return;
}

int main() {
    int n;
    while(scanf("%d",&n)!=EOF) {
        TreeNode* root=NULL;
        int data;
        for(int i=0; i<n; i++) {
            scanf("%d",&data);
            root=Insert(root,data);
        }
        PreOrder(root);
        printf("\n");
        InOrder(root);
        printf("\n");
        PostOrder(root);
        printf("\n");
    }
    return 0;
}
