/*
注意这是一棵完全二叉树，故有左子树为2*m,右子树为2*m+1
*/
#include<iostream>
using namespace std;
int func(int m,int n)
{
    if(m>n)
        return 0;
        else
            return 1 + func(m * 2,n) + func(m * 2 + 1,n);
}
int main()
{
    int m, n;
    while(cin>>m>>n)
    {
        cout << func(m, n) << endl;
    }
    return 0;
}