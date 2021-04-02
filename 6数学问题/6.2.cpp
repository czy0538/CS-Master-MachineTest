#include <iostream>
#include <vector>
#include <string>
using namespace std;
string Divide(string str, int x)
{
    int reminder = 0;
    //注意这是从高向低算的
    for (int i = 0; i < str.size(); ++i)
    {
        int current = reminder * 10 + str[i] - '0';
        str[i] = current / x + '0';
        reminder = current % x;
    }

    //找到首个非零下标
    int pos = 0;
    while (str[pos] == '0')
    {
        ++pos;
    }

    return str.substr(pos);
}

int main()
{
    string s;
    while (cin >> s)
    {
        vector<int> binary;
        while (s.size() != 0)
        {
            binary.push_back((s[s.size() - 1] - '0') % 2);//最低位取余
            s=Divide(s, 2);//除2
        }
        for (int i = binary.size() - 1; i >= 0;--i)
        {
            cout << binary[i];
        }
        cout << endl;
    }
    return 0;
}