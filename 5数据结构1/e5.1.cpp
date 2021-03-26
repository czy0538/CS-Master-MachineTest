#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)
            break;
        stack<int> s;
        for (int i = 0; i < n; ++i)
        {
            char c;
            //吃掉多余的空格，字符数字混用时注意，cin没有这个问题应该是
            getchar();
            scanf("%c", &c);
            switch (c)
            {
            case 'P':
                int t;
                scanf("%d", &t);
                s.push(t);
                break;
            case 'O':
                if (!s.empty())
                {
                    s.pop();
                }
                break;
            case 'A':
                if (s.empty())
                    printf("E\n");
                else
                    printf("%d\n", s.top());

                break;
            }
        }
        printf("\n");
    }
    return 0;
}