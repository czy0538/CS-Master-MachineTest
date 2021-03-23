/*
这个题难度不大，但注意输入的数据范围超过了10^9,必须用long long类型，且如果用c的输入
输出的话，必须用lld。这种情况下不如直接用cin，cout，目测效率更高甚至。
*/
#include<iostream>
#include<stack>
#include<cstdio>
using namespace std;
using LL = long long;
int main()
{
    int n;
    while(cin>>n)
    {
        stack<LL> s;
        for (int i = 0; i < n;++i)
        {
            LL t;
            scanf("%lld", &t);
            //cin >> t;
            s.push(t);
        }
        for (int i = 0; i < n;++i)
        {
            LL t;
            t = s.top();
            s.pop();
            printf("%lld ", t);
           // cout << t << " ";
        }
        //cout << endl;
        printf("\n");
    }
    return 0;
}