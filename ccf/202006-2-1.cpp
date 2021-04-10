#include<map>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
map<int, int> u, v;
int main()
{
    size_t n, a, b;
    while(scanf("%d %d %d",&n,&a,&b)!=EOF)
    {
        u.clear();
        v.clear();
        for (size_t i = 0; i < a;++i)
        {
            int index, value;
            scanf("%d %d", &index, &value);
            u[index] = value;
        }
        for (size_t i = 0; i < b; ++i)
        {
            int index, value;
            scanf("%d %d", &index, &value);
            v[index] = value;
        }
        int sum = 0;
        int all = min(a, b);
        int count = 0;
        for(auto iter:u)
        {
            if(count>all)
                break;
            auto t=v.find(iter.first);
            if (t!= v.end())
            {
                ++count;
                sum += t->second * iter.second;
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}