#include<iostream>
#include<cstdio>
using namespace std;
int main( )
{
    for(int a=0; a<=5; ++a)
        for(int b=0; b<=9; ++b)
            for(int c=0; c<=9;++c)
                if(532==a*100+b*110+c*12)
                        cout<<a<<" "<<b<<" "<<c<<endl;
    return 0;
}
