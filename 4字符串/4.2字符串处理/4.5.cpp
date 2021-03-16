#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
using namespace std;
int number[26];
int main()
{
    string str;
    while(cin>>str)
    {
        memset(number, 0, sizeof(number));
        for(const char &i:str)
        {
            if(i>='A'&&i<='Z')
            {
                number[i-'A']++;
            }
        }
        for (int i = 0; i < 26;++i)
        {
            printf("%c:%d\n",'A'+i,number[i]);
        }
    }
    return 0;
}