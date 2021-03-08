#include<iostream>
#include<cstdio>
using namespace std;
int daystab[2][13] = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, //非闰年
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, //闰年
};
int main()
{
    int m;
    scanf("%d", &m);
    while(m--)
    {
        int year, month, day, nums;
        scanf("%d %d %d %d", &year, &month, &day, &nums);
        int tab = 0;
        if((year%4==0&&year%100!=0)||year%400==0)
            tab = 1;
        
    }

}