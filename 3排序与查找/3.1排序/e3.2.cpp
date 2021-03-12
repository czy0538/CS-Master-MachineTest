#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const size_t MAXN = 10;

bool isOdd(const int &n)
{
    return n % 2 != 0;
}
bool CmpDesc(const int &a,const int &b)
{
    return a > b;
}
void print(int num[],const int& n)
{
    for (int i = 0; i < n;++i)
    {
        printf("%d ", num[i]);
    }
}
int main()
{
    int first;
    while (scanf("%d", &first) != EOF)
    {
        int odd[MAXN]; //奇数
        int even[MAXN];
        int n_odd = 0;
        int n_even = 0;
        if (isOdd(first))
        {
            odd[0] = first;
            n_odd++;
        }
        else
        {
            even[0] = first;
            n_even++;
        }
        for (int i = 1; i < 10; ++i)
        {
            scanf("%d", &first);
            if (isOdd(first))
            {
                odd[n_odd++] = first;
            }
            else
            {
                even[n_even++] = first;
            }
        }
        sort(odd, odd + n_odd, CmpDesc);
        sort(even, even + n_even);
        print(odd, n_odd);
        print(even, n_even);
        printf("\n");
    }
    return 0;
}