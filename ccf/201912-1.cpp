#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
bool has7(int a)
{
    if(a%7==0)
        return true;
    while(a)
    {
        if(a%10==7)
        {
            return true;
        }
        a /= 10;
    }
    return false;
}
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int ignore[4] = {};
        memset(ignore, 0, sizeof(ignore));
        int count = 0;
        int j = 1;
        while(count<n)
        {
            if(has7(j))
            {
                ignore[j % 4]++;
            }
            else
            {
                ++count;
            }
            ++j;
        }
        printf("%d\n%d\n%d\n%d\n", ignore[1], ignore[2], ignore[3], ignore[0]);
    }
    return 0;
}