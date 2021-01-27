#include<iostream>
#include<queue>

using namespace std;
/**
����������·��
**/

const int MAXN=10001;

struct Status {
    int n,time;
    Status(int n,int time):n(n),time(time){};
};

//���ĳһ����Ƿ��ѱ�����
bool visit[MAXN];

int BFS(int n,int k) {
    queue<Status> status;
    //ѹ���ʼ״̬(n,0)
    status.push(Status(n,0));
    //��ʼ״̬������
    visit[n]=true;
    while(!status.empty()) {
        Status current=status.front();
        status.pop();
        if(current.n==k) {
            return current.time;
        }
        //ת������״̬
        for(int i=0; i<3; i++) {
            Status next(current.n,current.time+1);
            if(i==0) {
                next.n+=1;
            } else if(i==1) {
                next.n-=1;
            } else {
                next.n*=2;
            }
            if(next.n<0||next.n>=MAXN||visit[next.n]) {
                continue;
            }
            status.push(next);
            visit[next.n]=true;
        }
    }
}

int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    printf("%d\n",BFS(n,k));
    return 0;
}
