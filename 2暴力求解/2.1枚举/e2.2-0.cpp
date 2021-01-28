#include <stdio.h>
int main()
{
    int n, x, y, z, xl;
    while (scanf("%d", &n) != EOF)
    {
        xl = n / 5 > 100 ? 100 : n / 5;
        for (x = 0; x <= xl; x++)
        {
            for (y = 0; y <= 100 - x; y++)
            {
                z = 100 - x - y;
                if (5 * 3 * x + 3 * 3 * y + z <= 3 * n)
                {
                    printf("x=%d,y=%d,z=%d\n", x, y, z);
                } //if
            }     //for
        }         //for
    }
}