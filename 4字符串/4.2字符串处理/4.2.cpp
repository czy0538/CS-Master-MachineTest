#include <iostream>
#include <string>
using namespace std;
const int dis = ('z' - 'a');
int main()
{
    string str;
    while (getline(cin, str))
    {
        for (string::iterator i = str.begin(); i < str.end(); ++i)
        {
            if (*i >= 'a' && *i <= 'y' || *i >= 'A' && *i <= 'Y')
            {
                *i += 1;
            }
            else if (*i == 'z' || *i == 'Z')
            {
                *i -= dis;
            }
        }
        cout << str << endl;
    }
    return 0;
}