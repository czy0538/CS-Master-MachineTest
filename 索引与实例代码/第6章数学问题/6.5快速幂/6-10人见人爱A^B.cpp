#include<iostream>

using namespace std;
/**�˼��˰�A^B��������������λ������ڿ����ݵĹ����н���ȡģ����
*������˼·���ڲ��϶�����ת��ָ����ͬʱ�������������Լ���ƽ��
*��������mod 1000
*/
int FastExponentiation(int a,int b,int mod) {
    int answer=1;
    while(b!=0) {
        if(b%2==1) {
            answer*=a;
            answer%=mod;
        }
        b/=2;
        a*=a;
        a%=mod;
    }
    return answer;
}
int main() {
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF) {
        if(a==0&&b==0)break;
        printf("%d\n",FastExponentiation(a,b,1000));
    }
    return 0;
}

