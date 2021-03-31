#include <cstring>
#include <string>
#include <iostream>
using namespace std;

//当前版本仅支持正整数之间比较，不支持负数操作
class BigInteger
{
    //数组最大长度
    static const size_t MAXN = 10000;

public:
    //存放数据的数组
    int digit[MAXN];
    //数字的长度
    int length;

public:
    //构造函数
    BigInteger();                    //初始化
    BigInteger(int x);               //整数转为高精度整数
    BigInteger(const string &str);   //字符串转为高精度整数
    BigInteger(const BigInteger &b); //高精度整数之间的赋值

    //高精度数据之间的运算,采用重载方式进行
    BigInteger operator+(const BigInteger &b); //加法
    BigInteger operator-(const BigInteger &b); //减法
    BigInteger operator*(const BigInteger &b); //乘法
    BigInteger operator/(const BigInteger &b); //除法
    BigInteger operator%(const BigInteger &b); //取余

    //比较运算符
    bool operator<=(const BigInteger &b); //小于等于
    bool operator==(const BigInteger &b); //等于

    //赋值运算符
    BigInteger operator=(int x);
    BigInteger operator=(string str);
    BigInteger operator=(const BigInteger &b);

    //输入输出运算符，需要重载成友元函数
    friend istream &operator>>(istream &in, BigInteger &x);        //输入
    friend ostream &operator<<(ostream &out, const BigInteger &x); //输出
};

//友元函数类外不用&
istream &operator>>(istream &in, BigInteger &x)
{
    string str;
    in >> str;
    x = str;//依赖对=的重载
    return in;
}

ostream &operator<<(ostream& out,const BigInteger &x)
{
    //注意先输出高位的数
    for (size_t i = x.length - 1; i != -1;--i)
    {
        out << x.digit[i];
    }
    return out;
}

BigInteger::BigInteger()
{
    memset(digit, 0, sizeof(digit)); //将整个digit设置为0
    length = 0;                      //length初始化
}

BigInteger::BigInteger(int x)
{
    memset(digit, 0, sizeof(digit)); //将整个digit设置为0
    length = 0;
    if (x == 0) //处理x=0时情况
        length = 1;
    while (x)
    {
        digit[length++] = x % 10;
        x /= 10;
    }
}

BigInteger::BigInteger(const string &str)
{
    memset(digit, 0, sizeof(digit));
    length = str.size();
    //将字符串转为数组，注意字符串中0位为最高位
    for (size_t i = 0; i < length; ++i)
    {
        digit[i] == str[length - i - 1] - '0';
    }
}

BigInteger::BigInteger(const BigInteger &b)
{
    memset(digit, 0, sizeof(digit));
    length = b.length;
    for (size_t i = 0; i < length; ++i)
    {
        digit[i] = b.digit[i];
    }
}

BigInteger BigInteger::operator=(int x)
{
    memset(digit, 0, sizeof(digit));
    length = 0;
    if (x == 0)
        length = 1;
    while (x)
    {
        digit[length++] = x % 10;
        x /= 10;
    }
    return *this;
}

BigInteger BigInteger::operator=(string str)
{
    memset(digit, 0, sizeof(digit));
    length = str.size();
    for (size_t i = 0; i < length; ++i)
    {
        digit[i] = str[length - i - 1] - '0';
    }
    return *this;
}

BigInteger BigInteger::operator=(const BigInteger &b)
{
    memset(digit, 0, sizeof(digit));
    length = b.length;
    for (size_t i = 0; i < length; ++i)
    {
        digit[i] = b.digit[i];
    }
    return 0;
}

int main()
{
    BigInteger x;
    cin >> x;
    cout << x;
    return 0;
}