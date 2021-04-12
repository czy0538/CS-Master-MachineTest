#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct Data
{
    int f;
    int j;
    double price;
    Data(int J, int F) : f(F), j(J)
    {
        price = (double)f/ j;
    }
};
bool myCmp(const Data&a,const Data&b)
{
    return a.price < b.price;
}

int main()
{
    int m, n;
    while(scanf("%d %d",&m,&n)!=EOF)
    {
        vector<Data> d;
        if(m==-1&&n==-1)
            break;
        if(n==0||m==0)
            printf("0.000\n");
        for (int i = 0; i < n;++i)
        {
            int j, f;
            scanf("%d %d", &j, &f);
            d.push_back(Data(j, f));
        }
        sort(d.begin(), d.end(), myCmp);
        double ans = 0;
        for (int i = 0;i<d.size()&&m!=0; i++)
        {
            if(m>=d[i].f)
            {
                ans += d[i].j;
                m -= d[i].f;
            }
            else
            {
                ans+=m/d[i].price;
                m = 0;
            }
        }
        printf("%.3f\n", ans);
    }
    return 0;
}