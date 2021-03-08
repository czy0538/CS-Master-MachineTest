#include<iostream>
#include<cstdio>
using namespace std;
int daystab[2][13] = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, //非闰年
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, //闰年
};
int main()
{
    int year, day;
    while(scanf("%d %d",&year,&day)!=EOF)
    {
        int tab = 0;
        int month = 0;
        if((year%100!=0&&year%4==0)||year%400==0)
            tab = 1;
        for (; day - daystab[tab][month] > 0;++month)
            day -= daystab[tab][month];
        ++month;
        printf("%04d-%02d-%02d\n", year,month,day);//注意补齐
    }
    return 0;
}