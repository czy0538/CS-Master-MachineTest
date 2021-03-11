#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const size_t MAXN = 100;
int data[MAXN] = {0};
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for (int i = 0; i < n;++i)
        {
            scanf("%d", &data[i]);
        }
        sort(data, data + n);
        for (int i = 0; i < n; ++i)
        {
            printf("%d ", data[i]);
        }
        printf("\n");
    }
    return 0;
}