#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    while (getline(cin, s))
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (i == 0 && s[i] >= 'a' && s[i] <= 'z')
                s[i] -= 32;
                //只处理空格和tab，因为回车换行天然的有getline处理了。即如果最后是回车换行的话，会在下个getline读入
            else if ((s[i - 1] == ' ' || s[i - 1] == '\t') && s[i] >= 'a' && s[i] <= 'z')
                s[i] -= 32;
        }
        cout << s << endl;
    }
    return 0;
}