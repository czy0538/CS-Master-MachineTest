/*
使用bool数组存储整个路程，覆盖了的为true，否则为false
采用贪心算法
将加油站按照价格升序排列，依次考查每个加油站的覆盖的区间
即按照价格从低到高尝试覆盖整个距离区间，如果能成功覆盖，则输出价格
反之说明无法走完全程，找到第一个无法覆盖的位置即为最大路程
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

//加油站数组
struct sta
{
    double pi;
    int di;
    //重载运算符方式实现价格升序排列
    bool operator<(const sta &b) const //这个const表明其不能修改类成员
    {
        return pi < b.pi;
    }
} a[500];
bool flag[30000]; //一个能覆盖整个路程区间的数组
int main()
{
    int cmax, d, davg, n;
    while (scanf("%d %d %d %d", &cmax, &d, &davg, &n) != EOF)
    {
        for (int i = 0; i < n; i++)
            scanf("%lf %d", &a[i].pi, &a[i].di);
        sort(a, a + n); //排序

        double sum = 0;                    //记录花费
        memset(flag, false, sizeof(flag)); //重置路程
        int max = cmax * davg;             //车加满油后的最远行驶距离
        int tmp;                           //当前加油站加油后最远行驶的距离（不会超过目的地）
        int cnt;                           //需要加油的距离
        for (int i = 0; i < n; i++)
        {
            //如果到终点距离<max,只需加上足够走到终点的油
            tmp = (a[i].di + max < d ? max : d - a[i].di);
            cnt = 0;
            //对从加油站开始区间进行检测，如果某个区间没有覆盖，则需要这个加油站加油
            for (int j = a[i].di; j < a[i].di + tmp; j++)
            {
                if (flag[j] == false)
                {
                    flag[j] = true;
                    cnt++;
                }
            }
            sum += cnt / (davg * 1.0) * a[i].pi; //加上在该加油站的花销
        }
        //check
        int i;
        for (i = 0; i < d; i++)
        {
            //有的路程没有被覆盖到说明走不到这里
            if (flag[i] == false)
            {
                printf("The maximum travel distance = %.2lf\n", (double)i);
                break;
            }
        }
        if (i == d)
        {
            printf("%.2lf\n", sum);
        }
    }
    return 0;
}
