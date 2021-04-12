#include <iostream>
#include <string>
#include <vector>
using namespace std;
string divide(string str, int x)
{
    int reminder = 0;
    for (int i = 0; i < str.size(); ++i)
    {
        reminder = reminder * 10 + str[i] - '0';
        str[i] = reminder / x + '0';
        reminder = reminder % x;
    }
    int pos = 0;
    while (str[pos] == '0')
    {
        ++pos;
    }
    str = str.substr(pos);
    return str;
}
string mulitiple(string str, int x)
{
    int carry = 0;
    for (int i = str.size() - 1; i >= 0; --i)
    {
        int current = carry + (str[i] - '0') * x;
        carry = current / 10;
        str[i] = current % 10 + '0';
    }
    while (carry != 0)
    {
        char c = carry % 10 + '0';
        carry /= 10;
        str = string(1, c) + str;
    }
    return str;
}
string add(string str, int x)
{
    int carry = x;
    for (int i = str.size() - 1; i >= 0 && carry != 0; --i) //没有进位了也就可以停了
    {
        int current = carry + str[i] - '0';
        str[i] = current % 10 + '0';
        carry /= 10;
    }
    while (carry != 0)
    {
        char c = carry % 10 + '0';
        carry /= 10;
        str = string(1, c) + str;
    }
    return str;
}
int main()
{
    string input;
    while (cin >> input)
    {
        vector<int> binary;
        while(input.size()!=0)
        {
            int t = (input[input.size()-1] - '0') % 2;
            binary.push_back(t);
            input = divide(input, 2);
        }
        string ans = "0";
        for (int i = 0; i < binary.size(); ++i)
        {
            //效率更高的一种写法，相当于提取了公因式
            ans = mulitiple(ans, 2);
            ans = add(ans, binary[i]);
        }
        cout << ans << endl;
    }
    return 0;
}