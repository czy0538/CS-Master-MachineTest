#include<iostream>
#include<cstdio>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    string input;
    while(cin>>input)
    {

        //transform(input.begin(), input.end(), input.begin(), ::tolower);//转小写
        unordered_map<char, vector<int>> data;
        vector<char> order;
        for (int i = 0;i<input.size();++i)
        {
            if (data.count(input[i]) == 0)
                order.push_back(input[i]);
            data[input[i]].push_back(i);

        }

        for(const char &c:order)
        {
            if(data[c].size()>1)
            {
                for (int i = 0; i < data[c].size() - 1;++i)
                {
                    printf("%c:%d,", c, data[c][i]);
                }
                printf("%c:%d\n", c, data[c][data[c].size() - 1]);
            }
        }


    }
    return 0;
}