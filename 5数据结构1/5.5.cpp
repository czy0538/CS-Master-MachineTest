#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main()
{
    string s;
    while (getline(cin, s))
    {
        string ans(s.size(), ' ');
        stack<int> l;
        for (size_t i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
            {
                l.push(i);
            }
            else if (s[i] == ')')
            {
                if (l.empty())
                    ans[i] = '?';
                else
                    l.pop();
            }
        }
        while (!l.empty())
        {
            ans[l.top()] = '$';
            l.pop();
        }
        cout << s << endl
             << ans << endl;
    }
    return 0;
}