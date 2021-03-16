#include<iostream>
#include<string>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
    string str;
    while(cin>>str)
    {
        unsigned int sum = 0;
        for (int i = 0;i<str.size();++i)
        {
            //加个判断感觉更快，避免复杂的立方的运算
            sum += str[i]=='0'?0:(str[i] - '0') * ((unsigned int)pow(2, str.size() - i) - 1);
        }
        printf("%d\n", sum);
    }
    return 0;
}