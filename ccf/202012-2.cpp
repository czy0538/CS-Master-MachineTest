/*
该题简化为给定m组数据，每组数据本身有一个值，其对应两个值： 该值下0,1的个数
找出其中某个数，要求大于等于大的数据1的个数和比他小的0的个数之和最大且该数本身最大
使用map（红黑树），保证了在logn的时间复杂度下的自然的遍历顺序下的asc
通过预处理数据和数学关系尽可能利用现成数据降低时间复杂度，最终时间复杂度为O(nlogn）
如果采用两次暴力遍历方法的话为O(n^2)
另一个思路与其类似，需要很多的数组，采用空间换时间的策略。
*/
#include <iostream>
#include <map>
#include <cstdio>
using namespace std;
struct Count//下标表示result的值，对应的值++
{
    int result[2] = {0, 0};
};
//Count 可以用pair替换，typedef pair<int, int> result;
int main()
{
    size_t m = 0;
    while (scanf("%d", &m) != EOF)
    {
        map<int, Count> data;//套一层struct的原因是不能直接放数组，但其实用pair更好
        int y, result;
        for (size_t i = 0; i < m; ++i) //nlogn
        {
            scanf("%d %d", &y, &result);
            data[y].result[result]++;//每次输入一个值，其对应0 1 增加
        }
        //起始数据
        map<int, Count>::iterator iter = data.begin();
        int max_y = iter->first;
        int max_c = 0;
        //因为可以合并c_1和c_0,故下面注释之前的代码为合并之前的，现存的为合并后的
        //int c_0 = 0;
        //int c_1 = iter->second.result[1];
        int c = iter->second.result[1];
        //预处理，计算出所有比最小元素大的1
        for (++iter; iter != data.end(); ++iter) //n
        {
            c += iter->second.result[1];
        }
        max_c = c;
        iter = data.begin();
        map<int, Count>::iterator p_iter = data.begin();
        for (++iter; iter != data.end(); ++iter, ++p_iter) //2n
        {

            c = c + p_iter->second.result[0] - p_iter->second.result[1];
            if (c >= max_c && iter->first > max_y)
            {
                max_c = c;
                max_y = iter->first;
            }
        }
        printf("%d\n", max_y);
    }
    return 0;
}