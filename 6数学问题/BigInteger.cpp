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
    size_t length;

public:
    //构造函数
    BigInteger();                    //初始化
    BigInteger(int x);               //整数转为高精度整数
    BigInteger(string str);          //字符串转为高精度整数
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
    bool operator>(const BigInteger &b);  //大于
    bool operator!=(const BigInteger &b); //不等于

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
    x = str; //依赖对=的重载
    return in;
}

ostream &operator<<(ostream &out, const BigInteger &x)
{
    //注意先输出高位的数
    for (size_t i = x.length - 1; i != -1; --i)
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

BigInteger::BigInteger(string str)
{
    memset(digit, 0, sizeof(digit));
    length = str.size();
    //将字符串转为数组，注意字符串中0位为最高位
    for (size_t i = 0; i < length; ++i)
    {
        digit[i] = str[length - i - 1] - '0';
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
    return *this;
}

BigInteger BigInteger::operator+(const BigInteger &b)
{
    BigInteger ans;
    int carry = 0;
    //大小为两个之间最大的
    for (size_t i = 0; i < length || i < b.length; ++i)
    {
        int current = digit[i] + b.digit[i] + carry;
        carry = current / 10;                   //如果有进位carry=1，否则为0
        ans.digit[ans.length++] = current % 10; //赋值同时改写length
    }
    //处理最后的进位
    if (carry != 0)
    {
        ans.digit[ans.length++] = carry;
    }
    return ans;
}

BigInteger BigInteger::operator-(const BigInteger &b)
{
    BigInteger ans;
    int carry = 0;
    //默认a>b,故只要满足a的长度即可。
    for (size_t i = 0; i < length; ++i)
    {
        int current = digit[i] - b.digit[i] - carry;
        if (current < 0)
        {
            carry = 1;
            current += 10;
        }
        ans.digit[ans.length++] = current;
    }
    //处理开头的0，注意条件顺序不可颠倒
    while (ans.length > 1 && ans.digit[ans.length - 1] == 0)
    {
        ans.length--;
    }
    return ans;
}

BigInteger BigInteger::operator*(const BigInteger &b)
{
    BigInteger ans;
    ans.length = length + b.length; //length初始化为两个的和,而a*b的长度不会超过两数长度的和
    //逐位乘
    for (size_t i = 0; i < length; ++i)
    {
        for (size_t j = 0; j < b.length; ++j)
        {
            ans.digit[i + j] += digit[i] * b.digit[j]; //乘的结果加
        }
    }
    //逐位处理进位
    for (size_t i = 0; i < ans.length; ++i)
    {
        ans.digit[i + 1] += ans.digit[i] / 10; //进位
        ans.digit[i] %= 10;
    }
    while (ans.length > 1 && ans.digit[ans.length - 1] == 0)
    {
        ans.length--;
    }
    return ans;
}

BigInteger BigInteger::operator/(const BigInteger &b)
{
    BigInteger ans;
    ans.length = length;
    BigInteger remainder = 0; //余数
    BigInteger temp = b;
    for (size_t i = length - 1; i != -1; --i)
    {
        if (!(remainder.length == 1 && remainder.digit[0] == 0))
        {
            for (size_t j = remainder.length - 1; j != -1; --j)
            {
                remainder.digit[j + 1] == remainder.digit[j];
            }
            remainder.length++;
        }
        remainder.digit[0] = digit[i];
        while (temp <= remainder)
        {
            remainder = remainder - temp;
            ans.digit[i]++;
        }
    }
    while (ans.length > 1 && ans.digit[ans.length - 1] == 0)
    {
        ans.length--;
    }
    return ans;
}

//与除法基本一致，只不过返回值为余数，而且不用计算ans
BigInteger BigInteger::operator%(const BigInteger &b)
{
    BigInteger remainder = 0; //余数
    BigInteger temp = b;
    for (size_t i = length - 1; i != -1; --i)
    {
        if (!(remainder.length == 1 && remainder.digit[0] == 0))
        {
            for (size_t j = remainder.length - 1; j != -1; --j)
            {
                remainder.digit[j + 1] == remainder.digit[j];
            }
            remainder.length++;
        }
        remainder.digit[0] = digit[i];
        while (temp <= remainder)
        {
            remainder = remainder - temp; //这里没有了ans
        }
    }
    return remainder;
}

bool BigInteger::operator!=(const BigInteger &b)
{
    if (length != b.length)
        return true;

    for (size_t i = 0; i < length; ++i)
    {
        if (digit[i] != b.digit[i])
            return true;
    }
    return false;
}

bool BigInteger::operator>(const BigInteger &b)
{
    if (length > b.length)
    {
        return true;
    }
    else if (length < b.length)
    {
        return false;
    }
    else
    {
        //大于从高位开始比较
        for (size_t i = 0; i < length; ++i)
        {
            if (digit[i] == b.digit[i])
                continue;
            else
                return digit[i] > b.digit[i];
        }
    }
    return false;
}

bool BigInteger::operator<=(const BigInteger &b)
{
    if (length < b.length)
    {
        return true;
    }
    else if (length > b.length)
    {
        return false;
    }
    else
    {
        for (size_t i = length - 1; i != -1; --i)
        {
            if (digit[i] == b.digit[i])
                continue;
            else
                return (digit[i] < b.digit[i]);
        }
    }
    return true;
}

int main()
{

    BigInteger a;
    BigInteger b;
    while (cin >> a >> b)
    {
        auto c = a * b;
        cout << c.length << " " << c << endl;
    }
    return 0;
}