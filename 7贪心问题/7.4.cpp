/*
区间贪心问题，遇到这种有开始，有结束，要求区间数目最多的，都选择按照结束时间排序的方法。
*/
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 100;
struct Data
{
    int start;
    int end;
} datas[MAXN];
//按结束时间降序排序
bool myCmp(const Data&a,const Data&b)
{
    return a.end < b.end;
}
int main()
{
    int n;
    while(scanf("%d",&n)&&n)
    {
        for (int i = 0; i < n;++i)
        {
            scanf("%d %d", &datas[i].start, &datas[i].end);
        }
        sort(datas, datas + n, myCmp);
        int current = 0;
        int ans = 0;
        for (int i = 0; i < n;++i)
        {
            if(datas[i].start>=current)
            {
                current = datas[i].end;
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}