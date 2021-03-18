/*
该代码适合把所有的x替换为y的情况
*/
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    while(getline(cin,s))
    {
        string a, b;
        cin >> a >> b;
        auto pos = s.find(a);
        while (pos != string::npos)
        {
            s = s.substr(0, pos) + b + s.substr(pos + a.size(), s.size() - pos - a.size());
            pos = s.find(a);
        }
        cout << s << endl;
    }
    return 0;
}