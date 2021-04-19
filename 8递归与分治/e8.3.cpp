#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<int> number;

//计算二进制，只保留为1的位
void find_num(int n, vector<int> &number)
{
    int temp = n;
    int num = 0;
    int count = 0;
    while (temp != 0)
    {
        num = temp % 2;
        temp = temp / 2;
        if (num == 1)
            number.push_back(count);
        count++;
    }
}

string find_dg(int n)
{
    if (n == 0)
        return "2(0)";
    if (n == 1)
        return "2";
    string res = "2(";
    vector<int> number;
    find_num(n, number);
    int len = number.size();
    for (int i = len - 1; i >= 0; i--)
    {
        if (i != len - 1)
            res += "+";
        res = res + find_dg(number[i]);
    }
    res += ")";
    return res;
}
string find(int n)
{
    string res;
    number.clear();
    find_num(n, number);
    int len = number.size();
    for (int i = len - 1; i >= 0; i--)
    {
        if (i != len - 1)
            res += "+";
        res = res + find_dg(number[i]);
    }
    return res;
}

int main()
{
    int n;
    while (cin >> n)
    {
        string res = find(n);
        cout << res << endl;
    }
    return 0;
}