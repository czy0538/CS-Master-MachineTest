#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
stack<int> d2b(unsigned int x)
{
    stack<int> binary;
    while (x)
    {
        binary.push(x % 2);
        x >>= 1;
    }
    return binary;
}
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        stack<int> binary = d2b(n);
        /*
        for (size_t i = binary.size() - 1; i >=0; --i)
        size_t是无符号整数类型，如果采用>=0会恒成立。
        这里应该改为！=-1，即为，或者改为<-1也是可以的，即小于溢出后的那个数
        */
        while(!binary.empty())
        {
            printf("%d", binary.top());
            binary.pop();
        }
        printf("\n");
    }
    return 0;
}