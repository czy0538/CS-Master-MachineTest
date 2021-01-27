#include<iostream>
using namespace std;
int reverse(int x);
int main()
{
    for(int i=0; i<=256; ++i)
    {
        if(i*i==reverse(i*i))
        {
            cout<<i<<endl;
        }
    }
    return 0;
}
int reverse(int x)
{
    int rev=0;
    while(x!=0)
    {
        rev*=10;
        rev+=x%10;
        x/=10;
    }
    return rev;
}
