#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct Country
{
    int gold_medals;
    int all_medals;
    int population;
    int id;
    double p_gold, p_medal;
    int rank[4];
    void count()
    {
        p_gold = (double)gold_medals / population;
        p_medal = (double)all_medals / population;
    }
    void printMin()
    {
        int r_i = 0, r = rank[0];
        for (int i = 1; i < 4; ++i)
        {
            if (rank[i] < r)
            {
                r_i = i;
                r = rank[i];
            }
        }
        printf("%d:%d\n", r, r_i + 1);
    }
};
bool CmpGold(const Country &a, const Country &b)
{
    return a.gold_medals > b.gold_medals;
}
bool CmpMedal(const Country &a, const Country &b)
{
    return a.all_medals > b.all_medals;
}
bool CmpP_gold(const Country &a, const Country &b)
{
    return a.p_gold > b.p_gold;
}
bool CmpP_medal(const Country &a, const Country &b)
{
    return a.p_medal > b.p_medal;
}
bool CmpId(const Country &a, const Country &b)
{
    return a.id < b.id;
}

int main()
{
    int m, n;
    while (scanf("%d %d", &n, &m) != EOF && n != 0)
    {
        //读入所有国家
        vector<Country> countries;
        for (int i = 0; i < n; ++i)
        {
            Country t;
            scanf("%d %d %d", &t.gold_medals, &t.all_medals, &t.population);
            t.id = i;
            t.count();
            countries.push_back(t);
        }
        //读入排名国家
        vector<int> rank_country;
        for (int i = 0; i < m; ++i)
        {
            int t;
            scanf("%d", &t);
            rank_country.push_back(t);
        }
        //写入金牌总数数据-0
        sort(countries.begin(), countries.end(), CmpGold);
        countries[0].rank[0] = 1;
        //处理两个国家排名相同，后面的国家顺延排名情况
        int same = 0;
        for (int i = 1; i < n; ++i)
        {
            if (countries[i - 1].gold_medals == countries[i].gold_medals)
            {
                countries[i].rank[0] = countries[i - 1].rank[0];
                ++same;
            }
            else
            {
                countries[i].rank[0] = countries[i - 1].rank[0] + 1 + same;
                same = 0;
            }
        }
        //写入奖牌数据-1
        same = 0;
        sort(countries.begin(), countries.end(), CmpMedal);
        countries[0].rank[1] = 1;
        for (int i = 1; i < n; ++i)
        {
            if (countries[i - 1].all_medals == countries[i].all_medals)
            {
                countries[i].rank[1] = countries[i - 1].rank[1];
                ++same;
            }
            else
            {
                countries[i].rank[1] = countries[i - 1].rank[1] + 1 + same;
                same = 0;
            }
        }
        //写入人均金牌数据-2
        same = 0;
        sort(countries.begin(), countries.end(), CmpP_gold);
        countries[0].rank[2] = 1;
        for (int i = 1; i < n; ++i)
        {
            if (countries[i - 1].p_gold == countries[i].p_gold)
            {
                countries[i].rank[2] = countries[i - 1].rank[2];
                ++same;
            }
            else
            {
                countries[i].rank[2] = countries[i - 1].rank[2] + 1 + same;
                same = 0;
            }
        }
        //写入人均奖牌数据-3
        same = 0;
        sort(countries.begin(), countries.end(), CmpP_medal);
        countries[0].rank[3] = 1;
        for (int i = 1; i < n; ++i)
        {
            if (countries[i - 1].p_medal == countries[i].p_medal)
            {
                countries[i].rank[3] = countries[i - 1].rank[3];
                ++same;
            }
            else
            {
                countries[i].rank[3] = countries[i - 1].rank[3] + 1 + same;
                same = 0;
            }
        }

        //输出
        sort(countries.begin(), countries.end(), CmpId);
        for (int i = 0; i < m; ++i)
        {
            countries[rank_country[i]].printMin();
        }
        printf("\n");
    }
    return 0;
}