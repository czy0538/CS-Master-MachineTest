#include <cstdio>
#include <cmath>
using namespace std;
const int MAXN = 10e5;
int num[MAXN];
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &num[i]);
        }
        int max, min;
        double mid;
        max = num[0];
        min = num[n - 1];
        if (max < min)
        {
            int temp;
            temp = max;
            max = min;
            min = temp;
        }
        if (n % 2 == 0)
        {
            mid = (num[n / 2] + num[n / 2 - 1]) / 2.0;//两个int除出来还是int
        }
        else
            mid = num[n / 2];

        if ((abs(mid) - abs((int)mid)) <= 0)
        {
            printf("%d %.0f %d\n", max, mid, min);
        }
        else
        {
            int sign = mid < 0 ? -1 : 1;
            printf("%d %.1f %d\n", max, round(mid*10)/10, min);
        }


    }

    return 0;
}