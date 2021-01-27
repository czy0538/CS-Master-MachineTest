#include<iostream>
#include<vector>

using namespace std;

/**����
*˼·��ʹ������ɸ��
*���弴�����޳������ı���
*/

const int MAXN=10001;
bool isPrime[MAXN];
vector<int> prime;

void Init() {
    for(int i=0; i<MAXN; i++) {
        isPrime[i]=true;
    }
    isPrime[0]=false;
    isPrime[1]=false;
    for(int i=2; i<MAXN; i++) {
        if(!isPrime[i])continue;
        prime.push_back(i);
        for(int j=i*i; j<MAXN; j+=i) {
            isPrime[j]=false;
        }
    }
}

int main() {
    Init();
    int n;
    while(scanf("%d",&n)!=EOF) {
        bool out=false;
        for(int i=0; i<prime.size()&&prime[i]<n; i++) {
            if(prime[i]%10==1) {
                out=true;
                printf("%d ",prime[i]);
            }
        }
        if(!out)printf("-1");
        printf("\n");
    }
    return 0;
}
