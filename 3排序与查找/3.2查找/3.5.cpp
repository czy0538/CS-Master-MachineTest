#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
const int MAXN = 100;
string yes = "YES";
string no = "NO";
int num[MAXN];
void binarySearch(const int &target,const int &n)
{
    int left = 0;
    int right = n - 1;
    while(left<=right)
    {
        int mid = (left + right) / 2;
        if (num[mid]<target)
        {
            left = mid + 1;
        }
        else if(num[mid]>target)
        {
            right = mid - 1;
        }
        else
        {
            cout << yes << endl;
            return;
        }
    }
    cout << no << endl;
}
int main()
{
    int n, m;
    while(scanf("%d",&n)!=EOF)
    {
        for (int i = 0; i < n;++i)
        {
            scanf("%d", &num[i]);
        }
        sort(num, num + n);
        scanf("%d", &m);
        for (int i = 0; i < m;++i)
        {
            int target;
            scanf("%d", &target);
            binarySearch(target, n);
        }
    }
    return 0;
}