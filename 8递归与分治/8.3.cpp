#include<iostream>
using namespace std;
using LL=long long;
LL func(LL n)
{
    if(n==0)
    return 0;
    if(n==1)
    return 1;
    return func(n - 1) + func(n - 2);
}

int main()
{
    LL n;
    while (cin>>n)
    {
        cout << func(n) << endl;
    }
    return 0;
}