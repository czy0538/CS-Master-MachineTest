#include<vector>
#include<iostream>
#include<cmath>
using namespace std;
struct Apple
{
    int raw = 0;
    int drop = 0;
    int no;
    Apple(int r,int n) : raw(r),no(n){};
};
int main()
{
    int n, m;
    while(cin>>n>>m)
    {
        vector<Apple> apple;
        for (int i = 1; i <= n;++i)
        {
            for (int j = 0; j <= m;++j)
            {
                int num;
                cin >> num;
                if(j==0)
                {
                    apple.push_back(Apple(num, i));
                }
                else
                {
                    apple[i-1].drop += abs(num);//注意这里的i是no
                }
            }
        }
        int t = apple[0].raw - apple[0].drop;
        int k = apple[0].no;
        int p = apple[0].drop;
        for (int i = 1; i < n;++i)
        {
            t += (apple[i].raw-apple[i].drop);
            if(apple[i].drop>p)
            {
                k = apple[i].no;
                p = apple[i].drop;
            }//不用比较等于，因为是按照升序遍历的
        }
        cout << t << " " << k << " " << p << endl;
    }
    return 0;
}