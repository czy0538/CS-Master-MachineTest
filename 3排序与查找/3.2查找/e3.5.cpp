#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN = 1000;
struct Data
{
    int x;
    int y;
} arr[MAXN];
int main()
{
    int n;
    while(scanf("%d", &n)!=EOF)
    {
        for (int i = 0; i < n;++i)
        {
            scanf("%d %d", &arr[i].x, &arr[i].y);
        }
        int min_x = arr[0].x;
        int min_y = arr[0].y;
        for (int i = 1; i < n;++i)
        {
            if(arr[i].x<min_x)
            {
                min_x = arr[i].x;
                min_y = arr[i].y;
            }
            else if(arr[i].x==min_x)
            {
                if(arr[i].y<min_y)
                    min_y = arr[i].y;
            }
        }
        printf("%d %d\n", min_x, min_y);
    }
    return 0;
}