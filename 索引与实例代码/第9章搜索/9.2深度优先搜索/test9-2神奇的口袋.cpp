#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
/**����Ŀڴ� 
*˼·��ÿ���������״̬0,1���ھ�״̬�� 
*��V>=40ʱ�˳������򲻶�����.״̬Ϊ(curr_V,curr_things) 
*/

int result=0;
int a[25];
int n;

void DFS(const int &index,const bool &isChosed,const int &V){
//	cout<<"index:"<<index<<" isChosed:"<<isChosed<<" V:"<<V<<" result:"<<result<<endl;
	
	if(V==40){
		++result;return;
	}
	if(V>40){
		return ;	
	}
	if(index==(n)){
		return;
	}else{
		DFS(index+1,true,V+a[index+1]);
		DFS(index+1,false,V);
	}
	return ;
}


int main(){
	cin>>n;
	//ԭ��ʹ��while(n--)�������ı���n��ֵ����DFS��ʹ��n���飡�� 
	for(int i=0;i<n;++i)cin>>a[i+1];
	DFS(0,false,0);
	
	cout<<result<<endl;

	return 0;
}

