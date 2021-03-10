#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int l, m;
    while(scanf("%d %d",&l,&m)!=EOF)
    {
        vector<bool> isTree(l+1, true);
        while(m--)
        {
            int beg, end;
            scanf("%d %d", &beg, &end);
            for (; beg <= end;++beg)
            {
                isTree[beg] = false;
            }
        }
        int count = 0;
        for(const bool &i:isTree)
        {
            if(i)
                ++count;
        }
        printf("%d\n", count);
    }
    return 0;
}