#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n;
    while (scanf("%d", &n) != EOF && n != 0)
    {
        int times=0;
        while (n != 1)
        {
            if (n % 2 == 0)
            {
                n /= 2;
            }
            else
            {
                n = (n * 3 + 1)/2;
            }
            ++times;
        }
        printf("%d\n", times);
    }
    return 0;
}