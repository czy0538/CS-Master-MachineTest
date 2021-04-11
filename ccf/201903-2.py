n=int(input())
s_l=[]
for i in range(0,n):
    s=input()
    s_l.append(s)
for i in s_l:
    str=i.replace('x','*')
    str=str.replace('/','//')
    ans=eval(str)
    if ans==24:
        print('Yes')
    else:
        print('No')
