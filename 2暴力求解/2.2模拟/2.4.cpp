#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
int main()
{
    int h = 0;
    while(cin>>h)
    {
        int n = 2 * (h - 1)+h;
        for (int i = 0; i < h;++i)
        {
            string s(2*i+h, '*');
            cout << setw(n) << right << s << endl;
            //printf("%s\n", s.c_str());//这里面不能用任意数作为左右对齐条件，而且string库的必须转换
        }
    }
    return 0;
}