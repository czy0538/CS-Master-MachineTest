#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;
int main()
{
    int n, p, m;
    while (scanf("%d %d %d", &n, &p, &m) != EOF)
    {

        queue<int> child;
        if (n == 0 && p == 0 && m == 0)
            break;

        // //所有小孩入队
        // for (int i = 1; i <= n; ++i)
        // {
        //     child.push(i);
        // }

        // //调整顺序从p开始
        // for (int i = 1; i < p; ++i)
        // {
        //     child.push(child.front());
        //     child.pop();
        // }

        //等效写法,
        //注意当p==n时候余数为0，需要单独处理
        child.push(p);
        for (int i = p + 1; i % n != p % n; ++i)
        {
            child.push(i % n == 0 ? n : i % n);
        }

        while (!child.empty())
        {
            for (int i = 1; i < m; ++i)
            {
                child.push(child.front()); //重新排队
                child.pop();
            }
            if (child.size() == 1)
            {
                printf("%d\n", child.front());
            }
            else
            {
                printf("%d,", child.front());
            }
            child.pop();
        }
    }
    return 0;
}