/*
代码复杂度分析：
1.输入，复杂度为O(n+m)
2.reset操作，复杂度为O(n)
3.find，复杂度为O(1)
总时间复杂度O(n+m)

基本思路：
采用贪心策略，每次选择距离服务器ip最远的代理ip作为代理服务器。
注意这里不需要真正遍历去找到具有最远ip的代理服务器，而是直接进行输入
对于不是代理服务器的ip，一定不需要更换ip
对于是代理服务器的ip，对其进行标记，并且标记该ip
如果所有的ip都被标记了，则说明此时发生了冲突，需要更换新的ip，否则不需要更换ip
*/

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

//重置代理状态
void reset_map(unordered_map<string, bool> &proxy)
{
    unordered_map<string, bool>::iterator iter = proxy.begin();
    while (iter != proxy.end())
    {
        iter->second = true;
        ++iter;
    }
}
int main()
{
    int n;
    while (cin >> n)
    {
        //本题无需排序且有大量查找操作，采用unordered_map具有常数级的查找复杂度
        unordered_map<string, bool> proxy; //key为ip，value为是否可作为代理服务器
        for (int i = 0; i < n; ++i)
        {
            string s;
            cin >> s;
            proxy[s] = true;
        }
        //count为可用代理服务器数量，当其为0说明必须更换代理服务器
        int count = n;
        int ans = 0;
        int m;
        cin >> m;
        for (int i = 0; i < m; ++i)
        {
            string s;
            cin >> s;
            //当该服务器是代理服务器且还没被标记时，需要标记该服务器，并检查是否都被标记
            if (proxy.find(s) != proxy.end() && proxy[s])
            {
                count--;
                proxy[s] = false;
                if (count == 0)
                {
                    ans++;
                    //注意标记当前ip，故count从n-1开始
                    count = n - 1;
                    reset_map(proxy);
                    //当前标记不可用
                    proxy[s] = false;
                }
            }
        }
        //本例中代理服务器不重复，故唯一一个可能出现无任何可用代理情况为：
        //代理服务器只有一个且需要更换代理服务器
        if (n == 1 && ans != 0)
        {
            cout << -1 << endl;
        }
        else
            cout << ans << endl;
    }
    return 0;
}