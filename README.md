# cs机试笔记

## 基本c++/c知识总结

### 1. 数据类型

- 10^9^ (32bits,2147483648)以内的数据用int,10^18^(64位)以内用long long，注意如果直接赋值long long数且大小超过了int范围，需要在立即数后面加ll。

- float有效精读只有6-7位，double有效精度有15-16位。**对于浮点数，尽量全部用double来存储。**浮点数常量默认为double的。

- 小写字母ascii码比大写字母大32，字符常量用单引号，A为65

- 转义字符 \n换行，\0空字符（用在c风格字符串结尾）

- 字符串在c中是字符数组，c++中有专门string类型

- 整数在做出发之前，除非想做整除，否则必须进行强制类型转换。

  ```c++
  int a,b;
  double c=a/b;//错误，结果仍未整数
  double c=a/1.0;//正确,进行了隐式类型转换
  ```

- 常量 cosnt 变量类型 变量名=变量;

- 宏：#define 标识符 常量，如果定义语句一定给所有变量加上（）,因为他是完全的替换

  ```c++
  #define ADD(a,b) ((a)+(b))
  ```

- c++中还用using可以用来起别名，using LL=long long ,这时不能用#define long long LL，可以用 typedef long long  LL

- 数组名本身就是一个指针，指向第一个元素

### 2. 运算符

- A ? B : C ，如果A为真，返回B的内容，否则返回C的内容
- int中无穷大数为 (1<<31)-1,即 0x3fffffff



### 3. 输入输出

[C/C++中的结束输入条件判断](https://blog.csdn.net/Jaster_wisdom/article/details/81161896)

除了string类型以外，尽量使用printf和scanf，因为速度会更快，他们在头文件#include<cstdio>中

#### 3.1 scanf

![image-20210218163024672](https://i.loli.net/2021/02/18/TsAPtrpx5izfjDe.png)

**注意double是lf，float是f**

```c++
scanf("格式控制",变量地址1，变量地址2，...);//注意一定是地址（指针），而不是变量名
```

scanf中格式控制的内容其实就是整个输入，只不过把数据换成了格式符，如对时间hh:mm:ss的处理

```c++
scanf("%d:%d:%d",&hh,&mm&ss);
```

- 大部分格式符输入是以空白符（空格，tab）结束的，%c会读入空格，%s是以空格和换行为标志的;

#### 3.2 printf

![image-20210218163015658](https://i.loli.net/2021/02/18/dcjbe5RhDkOg24t.png)

**注意double和float都是f**

- 真的需要输出转义字符时候在其前面在加一个\。
- %md 不足m位的int变量以m位为进行右对齐输出，高位补空格，超出m位保持不变。
- %0md不足m位的int变量以m位进行右对齐输出，高位补0
- %.mf小数保留m位输出（题目要求精确到小数点后xx位或保留xx位使用，是四舍六如五成双原则，四舍五入使用round函数）

#### 3.3 单个字符

getchar()和putchar()用来输入/输出单个字符，会捕捉到换行符，而不是像其他忽略他。



### 4.math函数

#include<cmath>

1. 绝对值std::abs(int/double x)

在使用std命名空间下，只需要使用abs,即可得到int，float，double类型的绝对值。

如果没用std命名空间，abs在cstdlib头文件中，只能针对int，fabs针对float和double。

2. double取整

   - floor(double x)：向下（数轴左）取整
   - ceil(double x)：向上（数轴右）取整

3. x^n^

   pow(double x,double n);
   
4. 算数平方根 sqrt(x)

5. 以e为底的对数：log(x)

6. 三角函数与手写的函数名相同

7. 反三角函数为a开头，asin,acos,atan

8. 四舍五入round(x)

### 5. 数组

note：如果申请的数组较大，应当定义到函数外面的全局变量区

#### 5.1 一维数组

```c++
数据类型 数组名[元素个数]={初始化列表}
```

如果想给整个数组赋初值0，可以等于一个空的大括号

#### 5.2 二维数组

二维数组赋初值需要每一行都用大括号，即二维数组理解成数组的数组，赋初值的时候需要对每个数组赋初值。

### 6. 函数

#### 6.1 以数组作为函数参数

数组不允许作为返回元素出现，但可以作为参数，多维数组第一维可以不写大小，第二维必须写。

### 7 多点测试输入输出格式

#### 7.1 输入

- 没有给定输入结束方式，默认为EOF结尾

  ```c++
  while(scanf(...)!=EOF)
  {
      ...
  }
  
  //针对c风格的字符串
  while(gets(str)!=NULL)
  {
      ...
  }
  
  //c++
  while(cin>>x)
  {
      ...
  }
  
  //c++风格字符串
  while(getline(cin,str,分隔符（默认为换行符))
  {
      ...
  }
  ```

  如果在一个程序中先使用cin>>str输入，然后再使用getline函数的话，需要再cin>>str之后使用cin.get()处理回车才行，也就是把回车当做cin.get()的输入，毕竟用户确实输入了一个回车。

#### 7.2 输出

- 前面要空行，最后一次不要空行

  这种一般与组数相关联，因此可以采用最后加入if来判断要不要有空行。

## 小代码段

### 1.求反序数

```c++
int reverse(int x)
{
    int revx=0;
    while(x!=0)
    {
        revx*=10;
        revx+=x%10;
        x/=10;
    }
    return revx;
}
```

### 2.浮点数的比较运算

简单的浮点数运算一般不会出现误差，但是如果多次运算的比较复杂的浮点数可能会有误差

```c
const double eps=1e-8;
const double Pi=acos(-1.0);
#define Equ(a,b) ((fabs((a)-(b)))<(eps))
#define More(a,b) (((a)-(b))>(eps))
#define Less(a,b) (((a)-(b))<(-eps))
#define MoreEqu(a,b) (((a)-(b))>(-eps))
#define LessEqu(a,b) (((a)-(b))<(eps))
```

### 3.闰年判断

```c
(i%4==0&&i%100!=0)||i%400==0
```

