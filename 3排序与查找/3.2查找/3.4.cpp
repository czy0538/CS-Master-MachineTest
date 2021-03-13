#include<iostream>
#include<cstdio>
using namespace std;
const size_t MAXN = 200;
int nums[MAXN];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for (int i = 0; i < n;++i)
        {
            scanf("%d", &nums[i]);
        }
        int x;
        scanf("%d", &x);
        int i = 0;
        for (; i < n; ++i)
        {
            if(nums[i]==x)
            {
                printf("%d\n", i);
                break;
            }
        }
        if(n==i)
            printf("%d\n", -1);
    }
    return 0;
}