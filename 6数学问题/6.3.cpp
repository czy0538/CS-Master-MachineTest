#include<string>
#include<sstream>
#include<iostream>
using namespace std;
string Multi(string str,int x)
{
    int carry = 0;
    //乘法是从低位开始算的
}
string Mod(string str, int x)
{
    int reminder = 0;
    //注意这是从高向低算的
    for (int i = 0; i < str.size(); ++i)
    {
        int current = reminder * 10 + str[i] - '0';
        str[i] = current / x + '0';
        reminder = current % x;
    }
    //int2str
    stringstream ss;
    ss << reminder;
    ss >> str;
    return str;
}

int main()
{
    string s;
    while(cin>>s)
    {
        cout << Mod(s, 233) << endl;
    }
    return 0;
}