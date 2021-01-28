#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n = 0;
    while (cin >> n)
    {
        bool flag = true;
        int x, y, z;
        cin >> x >> y >> z;
        int price = x * 1000 + y * 100 + z * 10;
        for (int a = 9; flag && a >= 1; --a) //一开始没考虑到多个结果输出一个的问题
        {
            for (int b = 9; b >= 0; --b)
            {
                int p = price + a * 10000 + b;//尽可能使用变量来减少运算，特别是乘除法
                if (p% n == 0)
                {
                    printf("%d %d %d\n", a, b, p / n);
                    flag = false;
                    break; //只能跳出一层循环
                }
            }
        }
        if (flag == true)
        {
            cout << 0 << endl;
        }
    }
    return 0;
}