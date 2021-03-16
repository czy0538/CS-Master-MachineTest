#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int rel = 0;
        for (int i = 0; i < n; ++i)
        {
            int w, score;
            scanf("%d %d", &w, &score);
            rel+=w*score;
        }
        if(rel<0)
            rel = 0;
        printf("%d\n", rel);
    }
    return 0;
}