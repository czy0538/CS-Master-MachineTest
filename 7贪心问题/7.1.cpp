#include<cstdio>
int main()
{
    int a;
    while(scanf("%d",&a)!=EOF)
    {
        if(a%2)
        {
            printf("0 0\n");
            continue;
        }
        int m = 0, M = 0;
        int c = a / 4;
        int r = (a - c * 4) / 2;
        m = r + c;
        M = a / 2;
        printf("%d %d\n", m, M);
    }
    return 0;
}