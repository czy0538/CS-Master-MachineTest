#include <string>
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
using var = pair<string, int>;
var add_decimal(string a, string b)
{
    //末尾补0
    if (a.size() < b.size())
        swap(a, b);
    b += string(a.size() - b.size(), '0');
    string c(a.size(), 0);
    int carry = 0;
    for (int i = a.size() - 1; i >= 0; --i)
    {
        c[i] = a[i] + b[i] - '0' + carry;
        if (c[i] > '9')
        {
            c[i] -= 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
    }
    int i;
    for (i = c.size() - 1; i >= 0; --i)
    {
        if (c[i] != '0')
            break;
    }
    if (i == -1)
        c.clear();
    else
        c = c.substr(0, i + 1);
    return var(c, carry);
}

string add_integer(string a, string b, int carry)
{
    //开头补0
    if (a.size() < b.size())
        swap(a, b);
    b = string(a.size() - b.size(), '0') + b;
    string c(a.size(), 0);
    for (int i = a.size() - 1; i >= 0; --i)
    {
        c[i] = a[i] + b[i] - '0' + carry;
        if (c[i] > '9')
        {
            c[i] -= 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
    }
    int i = 0;
    for (; i < c.size(); ++i)
    {
        if (c[i] != '0')
            break;
    }
    if (i == c.size())
        c = '0';
    else
        c = c.substr(i, c.size() - i);
    return c + '.';
}
int main()
{
    string a, b;
    while (cin >> a >> b)
    {
        int pos_a = a.find('.');
        int pos_b = b.find('.');
        var dec = add_decimal(a.substr(pos_a + 1, a.size() - pos_a - 1),
                              b.substr(pos_b + 1, b.size() - pos_b - 1));
        string integer = add_integer(a.substr(0, pos_a), b.substr(0, pos_b), dec.second);
        cout << integer << dec.first << endl;
    }
    return 0;
}
