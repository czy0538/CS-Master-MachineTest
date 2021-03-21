#include <iostream>
#include <cstdio>
using namespace std;
struct Point
{
    int x;
    int y;
};
const size_t MAXN = 10E3;
Point point_a[MAXN];
Point point_b[MAXN];
int main()
{
    size_t n, m;
    while (scanf("%d %d", &n, &m) != EOF)
    {
        size_t a = 0, b = 0;
        for (int i = 0; i < n; ++i)
        {
            int x, y;
            char c;
            scanf("%d %d %c", &x, &y, &c);
            if (c == 'A')
            {
                point_a[a].x = x;
                point_a[a].y = y;
                ++a;
            }
            else
            {
                point_b[b].x = x;
                point_b[b].y = y;
                ++b;
            }
        }
        for (int i = 0; i < m; ++i)
        {
            int x, y, z;
            scanf("%d %d %d", &z, &x, &y);
            bool t_a = (point_a[0].x * x + point_a[0].y * y + z < 0);
            bool t_b = (point_b[0].x * x + point_b[0].y * y + z > 0);
            if (t_a == t_b)
            {
                printf("No\n");
                continue;
            }
            else
            {
                bool flag = false;
                while (a--)
                {
                    if (t_a != (point_a[a].x * x + point_a[a].y * y + z < 0))
                    {
                        flag = true;
                        break;
                    }
                }
                if (flag)
                {
                    printf("No\n");
                    continue;
                }
                else
                {
                    while (b--)
                    {
                        if (t_b != (point_b[b].x * x + point_b[b].y * y + z < 0))
                        {
                            printf("No\n");
                            flag = true;
                            break;
                        }
                    }
                }
                if (!flag)
                    printf("Yes\n");
            }
        }
    }
    return 0;
}