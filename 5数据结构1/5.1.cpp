#include <iostream>
#include <vector>
using namespace std;
int my_sum(const int &x)
{
    int sum = 0;
    for (int i = 1; i < x; ++i)
    {
        if (x % i == 0)
        {
            sum += i;
        }
    }
    return sum;
}
void my_print(const vector<int> &a)
{
    for(auto iter = a.cbegin(); iter !=a.end(); ++iter)
    {
        cout << " " << *iter;
    }

}
int main()
{
    vector<int> numE;
    vector<int> numG;
    for (int i = 2; i <= 60; ++i)
    {
        int sum = my_sum(i);
        if (sum == i)
            numE.push_back(i);
        else if (sum > i)
            numG.push_back(i);
    }
    cout << "E:";
    my_print(numE);
    cout << endl;
    cout << "G:";
    my_print(numG);
    cout << endl;
    return 0;
}
/*
输出时候 "E:"和"G:"也要输出，就离谱
*/