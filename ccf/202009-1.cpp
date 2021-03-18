#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 201;
struct Data
{
    int d;
    int order;
} D[MAXN];

bool myCmp(const Data &a, const Data &b)
{
    if (a.d < b.d || (a.d == b.d && a.order < b.order))
        return true;
    return false;
}
int main()
{
    int n, X, Y;
    while (scanf("%d %d %d", &n, &X, &Y) != EOF)
    {
        for (int i = 1; i <= n; ++i)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            D[i].d = pow(x - X, 2) + pow(y - Y, 2);
            D[i].order = i;
        }
        sort(D + 1, D + n+1, myCmp);
        for (int i = 1; i <= 3;++i)
        {
            printf("%d\n", D[i].order);
        }
    }
    return 0;
}