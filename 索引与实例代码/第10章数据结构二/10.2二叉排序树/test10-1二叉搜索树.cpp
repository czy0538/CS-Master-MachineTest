#include<iostream>

using namespace std;
/**
���������������ǽ�������������
�ж϶���ǰ���������Ƿ�һ��
**/

struct TreeNode {
    char data;
    TreeNode *leftChild;
    TreeNode *rightChild;
    TreeNode(char num):data(num),leftChild(NULL),rightChild(NULL) {};
};

TreeNode* Insert(TreeNode*root,char data) {
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
void PreOrder(TreeNode *root,string &ans) {
    if(root==NULL)return;
    ans+=root->data;
    PreOrder(root->leftChild,ans);
    PreOrder(root->rightChild,ans);
    return;
}

int main() {
    int n;
    string str1,str2;
    while(scanf("%d",&n)!=EOF) {
        if(n==0)break;
        TreeNode* root=NULL;
        cin>>str1;
        for(int i=0; i<str1.size(); i++) {
            root=Insert(root,str1[i]);
        }
        for(int i=0; i<n; i++) {
            string ans1="",ans2="";
            TreeNode* root2=NULL;
            cin>>str2;
            for(int j=0; j<str2.size(); j++) {
                root2=Insert(root2,str2[j]);
            }
            PreOrder(root,ans1);
            PreOrder(root2,ans2);
            if(ans1==ans2){
                printf("YES\n");
            }else{
                printf("NO\n");
            }
        }
    }
    return 0;
}
