#include <iostream>
#include <cstdio>
using namespace std;
//每月天数
int daystab[2][13] = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, //非闰年
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, //闰年
};
int main()
{
    int year, month, day;
    int tab = 0;
    while (scanf("%d %d %d", &year, &month, &day) != EOF)
    {
        if ((year % 100 != 0 && year % 4 == 0) || year % 400 == 0)
        {
            tab = 1;//使用第二组数据
        }
        for (int i = 0; i < month - 1;++i)
        {
            day += daystab[tab][i];
        }
        printf("%d\n", day);
    }
    return 0;
}