#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const size_t MAXN = 1000;
int main()
{
    int n;
    int nums[MAXN];
    while (scanf("%d", &n) != EOF)
    {

        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &nums[i]);
        }
        if (n == 1)
        {
            printf("%d\n%d\n", nums[0], -1);
            continue;
        }
        sort(nums, nums + n);
        printf("%d\n", nums[n - 1]);
        for (int i = 0; i < n - 1; ++i)
        {
            printf("%d ", nums[i]);
        }
        printf("\n");
    }
    return 0;
}