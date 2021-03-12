#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
const size_t MAXN = 100;
struct Rat
{
    int weight;
    string hat;
    bool operator <(const Rat &b)
    {
        return weight > b.weight;
    }
} rats[MAXN];

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for (int i = 0; i < n;++i)
        {
            cin >> rats[i].weight >> rats[i].hat;
        }
        sort(rats, rats + n);
        for (int i = 0; i < n;++i)
        {
            cout << rats[i].hat << endl;
        }
    }
    return 0;
}
