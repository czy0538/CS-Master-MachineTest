#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    string str;
    while (cin >> str)
    {
        vector<string> s;
        for (int i = 1; i <= str.size(); ++i)
        {
            s.push_back(str.substr(str.size() - i, i));
        }
        sort(s.begin(), s.end());
        for (auto &i : s)
        {
            cout << i << endl;
        }
    }
    return 0;
}