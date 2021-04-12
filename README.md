

# 基本c++/c知识总结

## 1. 数据类型

- **10^9^ (32bits,2147483648)以内的数据用int,10^18^(64位)以内用long long**，注意如果直接赋值long long数且大小超过了int范围，需要在立即数后面加ll。

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

## 2. 运算符

- A ? B : C ，如果A为真，返回B的内容，否则返回C的内容
- int中无穷大数为 (1<<31)-1,即 0x3fffffff



## 3. 输入输出

[C/C++中的结束输入条件判断](https://blog.csdn.net/Jaster_wisdom/article/details/81161896)

除了string类型以外，尽量使用printf和scanf，因为速度会更快，他们在头文件#include<cstdio>中

- string 和 特别大的数的输入输出可以考虑cin cout

### 3.1 scanf

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

### 3.2 printf

![image-20210218163015658](https://i.loli.net/2021/02/18/dcjbe5RhDkOg24t.png)

**注意double和float都是f**

- double和float默认为6位

- 真的需要输出转义字符时候在其前面在加一个\。
- %md 不足m位的int变量以m位为进行右对齐输出，高位补空格，超出m位保持不变。
- %0md不足m位的int变量以m位进行右对齐输出，高位补0
- %.mf小数保留m位输出（题目要求精确到小数点后xx位或保留xx位使用，是四舍六如五成双原则，四舍五入使用round函数）

### 3.3 单个字符

getchar()和putchar()用来输入/输出单个字符，会捕捉到换行符，而不是像其他忽略他。



## 4.math函数

#include<cmath>

1. 绝对值std::abs(int/double x)

在使用std命名空间下，只需要使用abs,即可得到int，float，double类型的绝对值。

如果没用std命名空间，abs在cstdlib头文件中，只能针对int，fabs针对float和double。

2. double取整

   - **floor(double x)：向下（数轴左）取整**
   - **ceil(double x)：向上（数轴右）取整**

3. x^n^

   pow(double x,double n);
   
4. 算数平方根 sqrt(x)

5. 以e为底的对数：log(x)

6. 三角函数与手写的函数名相同

7. 反三角函数为a开头，asin,acos,atan

8. **四舍五入round(x)**

## 5. 数组

note：**如果申请的数组较大，应当定义到函数外面的全局变量区**

### 5.1 一维数组

```c++
数据类型 数组名[元素个数]={初始化列表}
```

如果想在初始化时给整个数组赋初值0，可以等于一个空的大括号

```c++
#include<cstring>
memset(数组名,0,sizeof(数组名))
```





### 5.2 二维数组

二维数组赋初值需要每一行都用大括号，即二维数组理解成数组的数组，赋初值的时候需要对每个数组赋初值。

## 6. 函数

### 6.1 以数组作为函数参数

数组不允许作为返回元素出现，但可以作为参数，多维数组第一维可以不写大小，第二维必须写。

## 7 多点测试输入输出格式

### 7.1 输入

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

### 7.2 输出

- 前面要空行，最后一次不要空行

  这种一般与组数相关联，因此可以采用最后加入if来判断要不要有空行。



## 8 stl内置算法使用

存在于头文件**algorithm**中

### 8.1 sort函数

- 时间复杂度为O(n*logn)，为不稳定排序

```c++
//原型1
template <class RandomAccessIterator>
  void sort (RandomAccessIterator first, RandomAccessIterator last);
//原型2
template <class RandomAccessIterator, class Compare>
  void sort (RandomAccessIterator first, RandomAccessIterator last, Compare comp);
```

- 参数说明

  - first，last为可以随机访问元素的迭代器或指针类型（数组名，begin(),end()）
  - 排序范围为[begin,end)
  - 默认为升序排序

- cmp函数

  - 通用形式(常用)

    ```c++
    bool Cmp(const T &a,const T &b)
    {
        //当需要a在b前面的时候反回true
    }
    ```

  - 类、结构体中重载运算符<形式，该情况下使用默认排序即可(涉及类的比较可以采用)

    ```cpp
    class Stu
    {
    public:
        int id;
        string name;
        Stu(int iid, string iname) : id(iid), name(iname) {}
        bool operator <(const Stu &i)
        {
            return id < i.id;
        }
    };
    int main()
    {
        vector<Stu> stus;
        stus.push_back(Stu(10, "10"));
        stus.push_back(Stu(1, "1"));
        sort(stus.begin(), stus.end());
        return 0;
    }
    ```

  - 使用对象作为cmp(基本不用)

    ```c++
    struct myclass {
      bool operator() (int i,int j) { return (i<j);}
    } myobject;
    sort (myvector.begin(), myvector.end(), myobject);
    ```

    

## 9 stl数据结构

### 9.1 map

头文件：#include\<map\>;using namespace std;

- map可以将任何基本类型（包括STL容器）映射到任何基本类型。
- map会自动按照键值的asc（从小到大）排序，这是由于map内部通过红黑树实现。

- map的定义

  ```c++
  map<typename1,typename2> name;
  //注意typename不能为数组，如果需要数组可以考虑用vector或者用struct里套一个数组
  struct Part
  {
      int part[2];
  };
  map<string,Part> name;
  
  typedef pair<int,int> p;
  map<stirng,p> name;
  ```

- map的访问:可以通过下标或者迭代器访问

  - 下标访问：

    即通过key访问，key是唯一的；

    如果map中没有key，则会新建一个key-value对；如果有，则会修改值；

  - 通过迭代器访问：

    map的迭代器仅支持$$ ++,--,!=,=,==$$运算符。

    ```c++
    //迭代器定义
    map<typename1,typename2>:: iterator iter;
    //元素值获取
    iter->first;//key值获取
    iter->second;//value值获取
    
    //遍历,注意不能用小于运算符
    for(auto i=name.begin();i!=name.end();++i)
    {
        //do something
    }
    
    name.begin()//返回第一个元素迭代器
    name.end()//返回尾后迭代器
    ```

- find(key),若找到返回对应迭代器，没找到返回end()，时间复杂度o(logn)

- count(key),若有返回1，没有返回0

- size()获取键值对数

- 插入函数

  ```c++
  // 插入单个键值对，并返回插入位置和成功标志，插入位置已经存在值时，插入失败
  pair<iterator,bool> insert (const value_type& val);
  
  //在指定位置插入，在不同位置插入效率是不一样的，因为涉及到重排
  iterator insert (const_iterator position, const value_type& val);
  返回的pair first为迭代器，second为是否插入成功
  ```

  

此外，c++还有unordered_map使用散列表实现，速度更快，但没有排序。



### 9.2 string

头文件 #include\<string\>

- 输入

  ```c++
  string str;
  cin>>str;//到空格终止
  getline(cin,str);//读到'\n'终止
  getline(cin,str,char);//读到char字符终止
  //注意：不能用scanf进行输入
  ```

- 输出

  ```c++
  cout<<str;//输出字符串全部内容
  //注意：不能直接用printf进行输出，而是要先进行转换
  printf("%s",str.c_str());
  ```

- 定义字符串

  ```c++
  string str;//str为空串
  string str="abc";//str为abc
  string str(n,c);//创建一个有n个c的串
  ```

- 重载了+=和比较运算符，意思很显然

- 访问方式

  ```c++
  str[1];//下标访问
  //迭代器访问，注意迭代器没有＜运算符,可以修改元素但不能改变元素数量 
  for(string:: iterator iter=str.begin();iter!=str.end();++iter)
  {
      cout<<*iter<<endl;
  }
  //遍历
  for(const char &i:str)
  {
       cout<<i<<endl;
  }
  
  for(char &i:str)
  {
       cout<<i<<endl;
  }
  ```

- 常用函数

  ```c++
  string str='abcd';
  str.size();//返回元素数量
  string::nops;//find函数未匹配时候的返回值
  //find函数查找子串str2，时间复杂度O(mn)，返回子串第一个字符位置
  str.find(str2);
  str.find(str2,pos);//从pos开始找
  
  str.substr(pos,len);//返回从pos开始，长度为len的子串
  str.substr(pos);//返回从pos开始，到结尾的子串
  str.substr(str1.find('x')+1,str.size()-str1.find('x')-1);//返回x后，到结尾的子串
  
  str.clear();//清空字符串
  str="";//等效写法
  str.erase();//等效写法
  	
  str.erase (size_t pos = 0, size_t len = npos);//从pos开始删除size_t个元素，第二个参数为空删除pos开始所有的元素
  str.erase (const_iterator p);//删除迭代器指向的元素
  str.erase (const_iterator first, const_iterator last);//删除[first,last)
      
  str.insert(pos,str2);//从pos开始插入str2
  str.insert(it1,it2,it3);//从it1迭代器位置开始，插入[it2,it3)
  ```

  



# 细节知识辨析

## 1. cin,cin.get(),cin.getline(),getline辨析

参考文献：

https://www.cnblogs.com/cthon/p/9198686.html（https://archive.is/zhG72）

https://blog.csdn.net/qq_33001647/article/details/54863824（https://archive.is/eRFL9）

## 2.size_t作为数组下标倒序输出数组时的问题

```c++
 for (size_t i = binary.size() - 1; i >=0; --i)
 {
     //do something
 }
```

size_t是无符号类型，故其>=0是恒成立的，这里如果想输出0号元素且能判断结束，需要注意在等于0以后，0-1会产生溢出，得到最大数，故应改成：

```c++
 for (size_t i = binary.size() - 1; i ！=-1或者i<-1; --i)
 {
     //do something
 }
```

## 3.运算符重载

- 如果作为类的成员函数，双目运算符也只需要写出第二个操作数
- 作为类的成员函数，类本身为第一个操作数
- 如果作为类的友元函数（非类的成员函数）进行重载，则所有操作数都要写出
- 输入输出运算法必须重载为友元函数

# 小代码段

## 1.求反序数

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

## 2.浮点数的比较运算

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

## 3.闰年判断

```c
(i%4==0&&i%100!=0)||i%400==0
```

## 4.二分查找

二分查找建立在被查找序列有序的基础上，该代码段以ASC为例，范围为[0,n-1]

```c++
//@arr 要查找的数组指针
//@n 数组大小
//@target 需要查找的目标元素
//@mid 元素的位置
//函数的返回值为是否查找成功
bool binarySearch(int arr[],const int &n,const int &target,int &mid)
{
    int left=0;
    int right=n-1;
    while(left<=right)
    {
        //mid=(left+right)/2;//一般没问题
        mid=left+(right-left)/2;//可以防止left、right都非常逼近范围时的溢出
        if(arr[mid]<target)
        {
            left=mid+1;
        }
        else if(arr[mid]>target)
        {
            right=mid-1;
        }
        else
        {
            return true;
        }
    }
    return false;
    
}
```

## 5.字符统计

```c++
#include<string>
#include<iostream>
#include<cstring>
using namespace std;
int number[128];//c++中共128个字符，故128的数组足以
int main()
{
    string str;
    while(getline(cin,str))
    {
        if(str=="#")
            return 0;
        string s;
        getline(cin, s);//每次重置数组
        for (int i = 0; i < s.size();++i)
        {
            number[s[i]]++;
        }
        for (int i = 0; i < str.size();++i)
        {
            cout << str[i]<<" "<<number[str[i]] << endl;
        }
    }
    return 0;
}
```

也可以采用map来实现，但map需要预先判断是否存在key，时间复杂度为O(logn)，故总的时间复杂度为O( nlongn),而采用如上方法为O(n)。

此外，把数组初始化在堆里每次使用memset赋值要比每次在栈里重新新建数组快。

对数组名sizeof返回的是整个数组的byte数。

## 6.浮点大数加减法

```c++
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str1, str2;
    int pos1, pos2;
    int num1, num2;
    while (cin >> str1 >> str2)
    {
        pos1 = str1.find('.', 0);
        pos2 = str2.find('.', 0);
        //.后的字符个数（不包括.)
        num1 = str1.size() - pos1;
        num2 = str2.size() - pos2;
        if (pos1 < pos2)
            str1.insert(0, pos2 - pos1, '0'); //前面补0
        else
            str2.insert(0, pos1 - pos2, '0');
        if (num1 < num2)
            str1.append(num2 - num1, '0'); //后面补0
        else
            str2.append(num1 - num2, '0');
        int c = 0; //进位
        for (int i = str1.size() - 1; i >= 0; i--)
        {
            if (str1[i] == '.')
                i--;
            int add = ((str1[i] - '0') + (str2[i] - '0') + c) % 10;
            c = ((str1[i] - '0') + (str2[i] - '0') + c) / 10;
            str1[i] = add + '0';
        }
        if (c != 0)
            str1.insert(0, 1, '0' + c);
        cout << str1 << endl;
    }
    return 0;
}
```

## 7.kmp算法

```c++
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

const int MAXN = 1000000;
const int MAXM = 10000;

int text[MAXN];
int pattern[MAXM];
int nextTable[MAXM];

void GetNextTable(int m){		// 创建next表
	int i = 0, j = -1;		
	nextTable[0] = -1;
	while (i < m) {			//因为找前后缀的匹配,所以让j=-1,使得第一个模式串从i=1开始
		if(j == -1 || pattern[i] == pattern[j]){	
			i++;
			j++;
			nextTable[i] = j;
		}else {
			j = nextTable[j];
		}
	}
}

int KMP(int n, int m){
	GetNextTable(m);
	int i = 0, j = 0;
	while(i < n && j < m){			// n是目标字符串，m是模式串
		if(j == -1 || text[i] == pattern[j]){	//匹配成功, 
			i++;					//或者是j==-1, 首部匹配失败，直接文本串向后移动一位
			j++;
		}else{						//匹配失败, 根据next数组移动模式串的j, 保持文本串的i不回溯, 
			j = nextTable[j];	
		}
	}
	if(j == m){				//移动到边界，匹配成功
		return i - j + 1;
        // j=nextTable[j];	//找出所有的匹配穿情况
	}else {
		return -1;
	}
}

int main(){
	int caseNumber;
	cin>>caseNumber;
	while(caseNumber--){
		int n, m;
		cin>>n>>m;
		for(int i=0;i<n;i++){
			cin>>text[i];
		}
		for(int j=0;j<m;j++){
			cin>>pattern[j];
		}
		cout<<KMP(n, m)<<endl;
	}
	return 0;
}

/*KMP理解
https://blog.csdn.net/v_JULY_v/article/details/7041827
https://www.zhihu.com/question/21923021
*/

```

## 8.十进制转二进制（高转低）

核心思想即不断的取余，右移，最终得到从低位到高位的该进制数；

如果是转为其他进制（高转低）也采用同样方法。

**该方法针对无符号数**

```c++
#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
stack<int> d2b(unsigned int x)
{
    stack<int> binary;//使用栈进行顺序的反转
    while (x)
    {
        binary.push(x % 2);
        x >>= 1;
    }
    return binary;
}
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        stack<int> binary = d2b(n);
        while(!binary.empty())
        {
            printf("%d", binary.top());
            binary.pop();
        }
        printf("\n");
    }
    return 0;
}
```

## 9. 大数和int运算

### 除法

```c++
string Divide(string str, int x)
{
    int reminder = 0;
    //注意这是从高向低算的
    for (int i = 0; i < str.size(); ++i)
    {
        int current = reminder * 10 + str[i] - '0';
        str[i] = current / x + '0';
        reminder = current % x;
    }

    //找到首个非零下标
    int pos = 0;
    while (str[pos] == '0')
    {
        ++pos;
    }

    return str.substr(pos);
}
```

### 取余

```c++
string Mod(string str, int x)
{
    int reminder = 0;
    //注意这是从高向低算的
    for (int i = 0; i < str.size(); ++i)
    {
        int current = reminder * 10 + str[i] - '0';
        str[i] = current / x + '0';
        reminder = current % x;
    }
    //int2str，<sstream>
    stringstream ss;
    ss<<reminder;
    ss>>str;
    return str;
}
```

###  乘法

```c++
string mulitiple(string str, int x)
{
    int carry = 0;
    for (int i = str.size() - 1; i >= 0; --i)
    {
        int current = carry + (str[i] - '0') * x;
        carry = current / 10;
        str[i] = current % 10 + '0';
    }
    while (carry != 0)
    {
        char c = carry % 10 + '0';
        carry /= 10;
        str = string(1, c) + str;
    }
    return str;
}
```

### 加法

```c++
string add(string str, int x)
{
    int carry = x;
    for (int i = str.size() - 1; i >= 0 && carry != 0; --i) //没有进位了也就可以停了
    {
        int current = carry + str[i] - '0';
        str[i] = current % 10 + '0';
        carry /= 10;
    }
    while (carry != 0)
    {
        char c = carry % 10 + '0';
        carry /= 10;
        str = string(1, c) + str;
    }
    return str;
}
```



## 10.四舍五入保留小数点后n位

```c++
#include<cstdio>
#include<cmath>
#define N 1
int main()
{
    double num;
    scanf("%lf",&num);//scanf读入double为lf
   	num=round(num*(1eN))*(1eN);
    printf("%.1f",num);//输出float和double都是f，而且写明位数，默认为6位
    return 0;
}
```

