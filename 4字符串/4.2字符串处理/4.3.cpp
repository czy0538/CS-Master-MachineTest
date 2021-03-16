#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    while (getline(cin, str))
    {
        if (str == "ENDOFINPUT")
        {
            return 0;
        }
        else if (str == "START" || str == "END")
            continue;
        else
        {
            for(string:: iterator i=str.begin();i<str.end();++i)
            {
                if(*i<='Z'&&*i>='A')
                {
                    *i = (*i - 'A' - 5 + 26) % 26 + 'A';
                }
            }
            cout << str << endl;
        }
    }
    return 0;
}