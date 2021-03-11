#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int keyTab[26] = {1, 2, 3, 1, 2, 3, 1, 2, 3,
                  1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};//数据表
int main()
{
    string input;
    while(cin>>input)
    {
        int time = 0;
        for (size_t i = 0; i < input.size();i++)
        {
            time += keyTab[input[i] - 'a'];//pushing time
            if (i != 0 && input[i] - input[i - 1] ==
            keyTab[input[i] - 'a'] - keyTab[input[i - 1] - 'a'])//计算间距
            {
                time += 2;//waitting time
            }
        }
        printf("%d\n", time);
    }
    return 0;
}