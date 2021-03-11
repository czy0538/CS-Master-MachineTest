#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
class Stu
{
public:
    int order;
    string name;
    int grade;
    void print()
    {
        cout << name << " " << grade << endl;
    }
};
bool CmpAsc(const Stu &a, const Stu &b)
{
    if (a.grade == b.grade)
        return a.order < b.order;
    return a.grade > b.grade;
}
bool CmpDesc(const Stu &a, const Stu &b)
{
    if (a.grade == b.grade)
        return a.order < b.order;
    return a.grade < b.grade;
}

int main()
{
    int n, o;
    while (scanf("%d", &n) != EOF)
    {
        scanf("%d", &o);
        vector<Stu> stus;
        for (int i = 0; i < n; ++i)
        {
            Stu temp;
            cin >> temp.name >> temp.grade;
            temp.order = i;
            stus.push_back(temp);
        }
        if (o)
        {
            sort(stus.begin(), stus.end(), CmpDesc);
        }
        else
        {
            sort(stus.begin(), stus.end(), CmpAsc);
        }
        for (Stu i : stus)
            i.print();
    }
    return 0;
}