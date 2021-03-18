#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n, k, t, xl, yd, xr, yu;
    while (scanf("%d %d %d %d %d %d %d", &n, &k, &t, &xl, &yd, &xr, &yu) != EOF)
    {
        int count_p = 0; //经过
        int count_s = 0; //逗留
        for (int i = 0; i < n; ++i)
        {
            int count_i = 0;
            bool isP = false;
            bool isS = false;
            for (int j = 0; j < t; ++j)
            {
                int x, y;
                scanf("%d %d", &x, &y);
                if (x >= xl && x <= xr && y >= yd && y <= yu)
                {
                    isP = true;
                    count_i++;
                    if (count_i >= k)
                    {
                        isS = true;
                    }
                }
                else
                {
                    count_i = 0;
                }

            }
            if(isP)
                count_p++;
            if (isS)
                count_s++;
        }
        printf("%d\n%d", count_p, count_s);
    }
    return 0;
}
