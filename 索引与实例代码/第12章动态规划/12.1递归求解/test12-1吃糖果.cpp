#include<iostream>
using namespace std;
/**
���ǹ�
쳲��������еı��壬��n��ķ�ʽ��n-1��n-2��ķ�ʽ��
**/

const int MAXN=21;
int dp[MAXN];
int main() {
    int n;
    dp[0]=0;
    dp[1]=1;
    for(int i=2; i<MAXN; i++) {
        dp[i]=dp[i-1]+dp[i-2];
    }
    while(scanf("%d",&n)!=EOF) {
        printf("%lld\n",dp[n+1]);
    }
    return 0;
}
