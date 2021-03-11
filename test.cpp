#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using LL = long long;
using namespace std;

class Stu
{
public:
    int id;
    string name;
    Stu(int iid, string iname) : id(iid), name(iname) {}
    bool operator()(const Stu &i,const Stu &j)
    {
        return i.id < j.id;
    }
    bool operator <(const Stu &i)
    {
        return id < i.id;
    }
}Cmp(0,"0");
int main()
{
    vector<Stu> stus;
    stus.push_back(Stu(10, "10"));
    stus.push_back(Stu(1, "1"));
    for (const auto &j : stus)
    {
        cout << j.id << endl;
    }
    //sort(stus.begin(), stus.end(), Cmp);

    sort(stus.begin(), stus.end());
    for(const auto &j:stus)
    {
        cout << j.id << endl;
    }
    return 0;
}