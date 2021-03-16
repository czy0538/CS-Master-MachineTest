#include<string>
#include<iostream>
#include<cstring>
using namespace std;
int number[128];
int main()
{
    string str;
    while(getline(cin,str))
    {
        if(str=="#")
            return 0;
        string s;
        getline(cin, s);
        memset(number, 0, sizeof(number));
        for (int i = 0; i < s.size();++i)
        {
            number[s[i]]++;
        }
        for (int i = 0; i < str.size();++i)
        {
            cout << str[i]<<" "<<number[str[i]] << endl;
        }
    }
    return 0;
}