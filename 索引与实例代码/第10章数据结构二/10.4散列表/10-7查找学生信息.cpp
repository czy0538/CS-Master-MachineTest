#include<iostream>
#include<map>

using namespace std;
/**����ѧ����Ϣ
ʹ��map����߼�������Ч��
*/

int main() {
    int n;
    cin>>n;
    getchar();//�Ե��س�
    map<string, string> student;
    string key,str;
    for(int pos,i=0; i<n; ++i) {
        getline(cin,str);
        pos = str.find(" ");
        key = str.substr(0,pos);
        student[key]=str;
    }
    int m;
    scanf("%d",&m);
    while(m--) {
        cin>>key;
        string answer = student[key];
        if(answer=="")answer="No Answer!";
        cout<<answer<<endl;
    }

    return 0;
}

