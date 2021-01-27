#include<iostream>
using namespace std;
int main()
{
    int a=1;
    for(int b=0; b<=9; ++b)
        for(int c=0; c<=9; ++c)
            for(int d=0; d<=9; ++d)
                if(0==8999*a+890*b-10*c-991*d)
                    cout<<a*1000+b*100+c*10+d<<endl;
    return 0;
}
