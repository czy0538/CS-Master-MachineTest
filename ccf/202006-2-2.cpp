/*
该方法时间复杂度为O(a+b)
只需要进行一次遍历，即可
如果下标相等，则相乘
不相等，则小的++
*/
#include<cstdio>
const int MAXN = 5e+5;//5*10^5+5
struct Node
{
    int idx;
    int val;
} vec1[MAXN], vec2[MAXN];
int main()
{
    int n, a, b, p1 = 0, p2 = 0;
    while(scanf("%d %d %d",&n,&a,&b)!=EOF)
    {
        long long ans = 0;
        for (int i = 0; i < a; i++)
            scanf("%d %d", &vec1[i].idx, &vec1[i].val);
        for (int i = 0; i < b; i++)
            scanf("%d %d", &vec2[i].idx, &vec2[i].val);
        while (p1 < a && p2 < b)
        {
            if (vec1[p1].idx == vec2[p2].idx)
            {
                ans += vec1[p1].val * vec2[p2].val;
                p1++;
                p2++;
            }
            else if (vec1[p1].idx < vec2[p2].idx)
                p1++;
            else
                p2++;
        }
        printf("%lld", ans);
    }

    return 0;
}