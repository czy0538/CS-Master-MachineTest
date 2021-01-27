#include <iostream>
using namespace std;

bool about_seven(int x)
{
    if (x % 7 == 0)
    {
        return true;
    }
    else
    {
        while (x != 0)
        {
            if (x % 10 == 7)
            {
                return true;
            }
            x = x / 10;
        }
        return false;
    }
}

int main()
{
    int n;
    int result = 0;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        if (about_seven(i) == false)
            result = result + i * i;
    }
    cout << result;
}
