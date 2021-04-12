#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
const int MAXN = 1e6;
int a[MAXN];
int b[MAXN];
bool myCmp(int a, int b) { return a > b; }
int main()
{
    int l;
    scanf("%d", &l);
    while(l--)
    {
        int m, n;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n;++i)
        {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < m; ++i)
        {
            scanf("%d", &b[i]);
        }
        sort(a, a + n,myCmp);
        sort(b, b + m);
        int ans = 0;
        for (int i = 0; i < m && i < n;++i)
        {
            if(a[i]-b[i]>0)
                ans += a[i] - b[i];
            else
                break;
        }
        printf("%d\n", ans);
    }
    return 0;
}