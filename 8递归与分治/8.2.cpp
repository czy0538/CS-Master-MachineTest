#include<iostream>
using namespace std;
using LL = long long;
LL function(LL n)
{
    if(n==1)
        return 2;
    return 3 * function(n - 1) + 2;
}
int main()
{
    int n;
    while(cin>>n)
    {
        cout << function(n) << endl;
    }
    return 0;
}