#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    int n = 0;
    vector<int> vc;
    vc.push_back(1);
    vc.push_back(2);
    vc.push_back(3);
    cout << *(++vc.begin()) << endl;
    cout << *(++vc.begin()) << endl;
    return 0;
}