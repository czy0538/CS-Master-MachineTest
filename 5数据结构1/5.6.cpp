#include <string>
#include <sstream>
#include <iostream>
#include <stack>
#include <cstdio>
#include <unordered_map>
using namespace std;
unordered_map<string, double> priority =
    {{"#", 0}, {"$", 1}, {"+", 2}, {"-", 2}, {"*", 3}, {"/", 3}};
double s2d(const string &s)
{
    stringstream ss;
    ss << s;
    double ans;
    ss >> ans;
    return ans;
}
bool isDigital(const string &s)
{
    return (s != "+" && s != "-" && s != "*" && s != "/" && s != "$");
}
double calculate(double a, double b, const string &op)
{
    if (op == "+")
        return a + b;
    else if (op == "-")
        return a - b;
    else if (op == "*")
        return a * b;
    else if (op == "/")
        return a / b;
    return 0x3fffffff;
}
int main()
{
    string s;
    while (getline(cin, s))
    {
        if(s=="0")
            break;
        s += " $";
        stack<string> oper;
        oper.push("#");
        stack<double> data;
        stringstream ss;
        ss << s;
        string t;
        while (ss >> t)
        {
            if (isDigital(t))
            {
                data.push(s2d(t));
            }
            else
            {
                while(true)
                {
                    if (priority[oper.top()] < priority[t])
                    {
                        oper.push(t);
                        break;
                    }
                    else
                    {
                        //先弹出来的为右操作数
                        double b = data.top();
                        data.pop();
                        double a = data.top();
                        data.pop();
                        data.push(calculate(a, b, oper.top()));
                        oper.pop();
                        //需要继续用当前运算符与栈中的运算符比较，若还是栈中大继续弹
                    }
                }
            }
        }
        printf("%.2f\n", data.top());
    }
    return 0;
}