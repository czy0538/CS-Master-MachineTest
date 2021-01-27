#include<iostream>
using namespace std;
int main()
{
    int n=0;
    while(cin>>n)
    {
        int sum=0;
        for(int i=1; i<=n; ++i)
        {

            if(i%7==0)//之前用i/7判断是错误的，i%7是看余数的
                continue;
            else
            {
                int temp=i;
                while(temp!=0)
                {
                    int x=temp%10;
                    if(7==x)
                        break;
                    temp/=10;
                }
                if(temp!=0)
                    continue;
                sum+=i*i;
            }


        }
        cout<<sum<<endl;
    }
}
