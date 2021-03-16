#include<iostream>
#include<string>
using namespace std;
int main()
{
    string a, b;
    while(cin>>a>>b)
    {
        int sum=0;
        for (string::iterator iter_a = a.begin();iter_a<a.end();++iter_a)
        {
            for (string::iterator iter_b = b.begin(); iter_b < b.end(); ++iter_b)
            {
                sum += (*iter_a - '0') * (*iter_b - '0');
            }
        }
        cout << sum << endl;
    }
    return 0;
}