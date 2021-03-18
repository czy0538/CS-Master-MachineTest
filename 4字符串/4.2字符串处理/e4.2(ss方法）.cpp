#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main()
{
    stringstream ss;
    string str;
    getline(cin, str);//必须先把整个字符串读进来，否则不知道要替换的单词是谁
    ss << str;
    string a, b;
    cin >> a >> b;
    string word;
    str.clear();
    //逐个字符处理
    while(ss>>word)
    {
        word = word == a ? b : word;
        str += word + " ";
    }
    str.erase(str.end() - 1);//删除尾后空格
    cout << str;

    return 0;
}