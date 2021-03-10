/*
思路：计算出两年之间差值，同时把月份归结到1月1号，再补上天数之间的差值
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int datasTab[2][12] = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, //非闰年
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}  //闰年
};
int isLeapYear(const int &year)
{
    return (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0) ? 1 : 0;
}
void countDays(const int &year, int month, int &day)
{
    int tab = isLeapYear(year);
    month--;
    while (month--)
    {
        day += datasTab[tab][month];
        //一开始写成了day += datasTab[tab][month - 1];，但为什么不报错！！！
    }
}
int allYearDays(const int &year)
{
    return isLeapYear(year) ? 366 : 365;
}
int main()
{
    int data1, data2;
    while (scanf("%d\n%d", &data1, &data2) != EOF)
    {
        if (data1 > data2)
            swap(data1, data2);
        int year1, month1, day1;
        int year2, month2, day2;
        year1 = data1 / 10000;
        year2 = data2 / 10000;
        month1 = (data1 / 100) % 100;
        month2 = (data2 / 100) % 100;
        day1 = data1 % 100;
        day2 = data2 % 100;
        int ans = 1;
        for (; year1 != year2; ++year1)
        {
            ans += allYearDays(year1);
        }
        countDays(year2, month2, day2);
        countDays(year1, month1, day1);

        printf("%d\n", ans + day2 - day1);
    }
    return 0;
}