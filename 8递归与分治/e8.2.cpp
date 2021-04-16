/*
采用交换法，足以处理所有的全排列问题
如果最后没有要求按照某种顺序的话，直接输出即可
该题也可以直接用c++的算法库里的好东西
string s;
while (getline(cin, s)) {
    sort(s.begin(), s.end());
    do
    {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));
    cout << endl;
}
*/
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
