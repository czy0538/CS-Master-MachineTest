#include <string>
#include <unordered_set>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;
set<string> ans;//排序用
void dfs(string s, int x)
{
    if (x == s.size() - 1)
    {
        ans.insert(s);
        return;
    }
    else
    {
        unordered_set<char> st; //存放已经处理过了的字符
        for (int i = x; i < s.size(); ++i)
        {
            //已经发生过交换，证明是重复元素，故跳过
            if (st.find(s[i]) != st.end())
            {
                continue;
            }
            else
            {
                st.insert(s[i]);
                swap(s[i], s[x]); //交换
                dfs(s, x + 1);
                swap(s[i], s[x]); //换回
            }
        }
    }
}
int main()
{
    string s;
    while (cin >> s)
    {
        ans.clear();
        dfs(s, 0);
        for (const auto &i:ans)
        {
            cout << i << endl;
        }
    }
    return 0;
}
