#include <iostream>
using namespace std;
using LL = long long;
LL factorial(LL a)
{
    if (a == 1)
        return 1;
    else
        return a * factorial(a - 1);
}
int main()
{
    LL n;
    while(cin>>n)
    {
        cout << factorial(n) << endl;
    }
    return 0;
}