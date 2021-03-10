#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using LL = long long;
using namespace std;
int isLeapYear(const int &year)
{
    return (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0) ? 1 : 0;
}
int main()
{
    int year = 2021;
    cout << isLeapYear(year) << endl;
    return 0;
}