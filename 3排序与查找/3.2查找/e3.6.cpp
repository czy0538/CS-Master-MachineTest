#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 80;
int arr[MAXN];
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &arr[i]);
        }
        //处理开头，注意k>4故不用考虑是否重合
        if (arr[0] != arr[1])
        {
            printf("%d ", 0);
        }

        for (int i = 1; i < n - 1; ++i)
        {
            if ((arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) ||
                (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]))
                printf("%d ", i);
        }
        //处理结尾
        if (arr[n - 1] != arr[n - 2])
        {
            printf("%d ", n - 1);
        }
        printf("\n");
    }
    return 0;
}