#include <iostream>
using namespace std;
#include <string>
int main()
{
    string str1, str2;
    int pos1, pos2;
    int num1, num2;
    while (cin >> str1 >> str2)
    {
        pos1 = str1.find('.', 0);
        pos2 = str2.find('.', 0);
        num1 = str1.size() - pos1;
        num2 = str2.size() - pos2;
        if (pos1 < pos2)
            str1.insert(0, pos2 - pos1, '0'); //前面补0
        else
            str2.insert(0, pos1 - pos2, '0');
        if (num1 < num2)
            str1.append(num2 - num1, '0'); //后面补0
        else
            str2.append(num1 - num2, '0');
        int c = 0; //进位
        for (int i = str1.size() - 1; i >= 0; i--)
        {
            if (str1[i] == '.')
                i--;
            int add = ((str1[i] - '0') + (str2[i] - '0') + c) % 10;
            c = ((str1[i] - '0') + (str2[i] - '0') + c) / 10;
            str1[i] = add + '0';
        }
        if (c != 0)
            str1.insert(0, 1, '0' + c);
        cout << str1 << endl;
    }
    return 0;
}