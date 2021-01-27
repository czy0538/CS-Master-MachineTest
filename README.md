# cs机试笔记

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

