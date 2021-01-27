#include<iostream>
#include<algorithm>
using namespace std;
/**
�����Լ۱��������
**/
const int MAXN=1000;

struct JavaBean {
    double weight;
    double cost;
};

bool Compare(JavaBean x,JavaBean y) {
    return (x.weight/x.cost)>(y.weight/y.cost);
}

int main() {
    JavaBean bean[MAXN];
    int m,n;
    while(scanf("%d%d",&m,&n)!=EOF) {
        if(m==-1&&n==-1)break;
        for(int i=0; i<n; i++) {
            scanf("%lf%lf",&bean[i].weight,&bean[i].weight);
        }
        sort(bean,bean+n,Compare);
        double answer=0;
        for(int i=0; i<n; i++) {
            if(m>=bean[i].cost) {
                m-=bean[i].cost;
                answer+=bean[i].weight;
            } else {
                answer+=(m/bean[i].cost)*bean[i].weight;
                break;
            }
        }
        printf("%.3f\n",answer);
    }
    return 0;
}
