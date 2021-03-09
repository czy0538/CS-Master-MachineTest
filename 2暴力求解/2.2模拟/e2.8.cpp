#include <iostream>
#include <cstdio>
using namespace std;
int datas[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main()
{
    int m;
    scanf("%d", &m);
    while (m--)
    {
        int year, month, day;
        scanf("%d %d %d", &year, &month, &day);
        if (day + 1 > datas[month - 1])
        {
            if(12==month)
            {
                ++year;
                day = 1;
                month = 1;
            }
            else{
                ++month;
                day = 1;
            }

        }
        else
        {
            ++day;
        }
        printf("%04d-%02d-%02d\n", year, month, day);
    }
    return 0;
}