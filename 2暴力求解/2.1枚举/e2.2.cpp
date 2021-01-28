/*
太不细心了，所有的<=都写成了小于而且浪费了很长时间
*/
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n = 0;
    while (cin >> n)
    {
        for (int x = 0; x <= n / 5; ++x)
        {
            for (int y = 0; 5 * x + 3 * y <= n; ++y)

                for (int z = 0; x * 15 + y * 9 + z <= 3 * n; ++z)
                {
                    if (100 == x + y + z)
                    {
                        printf("x=%d,y=%d,z=%d\n", x, y, z);
                    }
                }
        }
    }
    return 0;
}