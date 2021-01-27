#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
/**��С������ 
*ʵ��һ�����鼯���ϲ������Ҳ�ѹ���� 
*����С�������ϵı�Ȩ�ۼӣ�ԭ����ý� 
*/

struct Edge{
	int from;
	int to;
	int length;
	bool operator<(const Edge& e)const{
		return length<e.length;
	}
};

#define MAXN 100
Edge edge[MAXN*MAXN];
int father[MAXN];
int height[MAXN]={0};

//���Ŷ����������ݵ����룬��ÿһ�������������Ҫ����һ�γ�ʼ�� 
void Initial(const int &n){
	for(int i=0;i<n;++i){
		father[i]=i;
		height[i]=0;
	}
}

int Find(const int &x){
	if(x!=father[x])father[x]=Find(father[x]);
	return father[x];
}

void Union(int x,int y){
	x = Find(x);
	y = Find(y);
	if(x!=y){
		if(height[x]<height[y])
			father[x]=y;
		else if(height[x]>height[y])
			father[y]=x;
		else{
			father[y]=x;
			++height[x];
		}
	}
	return ;
}

int Kruskal(const int &n,int edgeNum){
	Initial(n);
	sort(edge,edge+edgeNum);
	int sum=0;
	for(int i=0;i<edgeNum;++i){
		Edge curr=edge[i];
		if(Find(curr.from)!=Find(curr.to)){
			Union(curr.from,curr.to);
			sum+=curr.length;
		}
	}
	return sum;
} 

int main(){
	int n,edgenum;
	while(cin>>n){
		if(n==0)break;
		edgenum = n*(n-1)/2;
		for(int i=0;i<edgenum;++i){
			cin>>edge[i].from>>edge[i].to>>edge[i].length;
		}

		int answer = Kruskal(n,edgenum);

		cout<<answer<<endl;
	}


	return 0;
}

