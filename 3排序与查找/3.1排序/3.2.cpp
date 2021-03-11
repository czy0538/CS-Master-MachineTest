#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const size_t MAXN = 100;
class Stu
{
public:
    int id;
    int grade;
    bool operator<(const Stu &i)
    {
        if (grade == i.grade)
            return id < i.id;
        return grade < i.grade;
    }
    void print()
    {
        printf("%d %d\n", id, grade);
    }

} stu[MAXN];

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; ++i)
        {
            scanf("%d %d", &stu[i].id, &stu[i].grade);
        }
        sort(stu, stu + n);
        for (int i = 0; i < n; ++i)
            stu[i].print();
    }
    return 0;
}