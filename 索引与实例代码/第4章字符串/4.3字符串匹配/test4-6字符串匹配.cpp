#include<iostream>
#include<string>

using namespace std;

//�����ַ��Ƿ���ͬһ��ĸ
int match(char c1,char c2) {
    if(c1<='Z'&&c1>='A') {
        c1+='a'-'A';
    }
    if(c2<='Z'&&c2>='A') {
        c2+='a'-'A';
    }
    return (c1==c2);
}

int main() {
    int n,j,k;
    cin>>n;
    string str[n],temp;
    for(int i=0; i<n; i++) {
        cin>>str[i];
    }
    cin>>temp;
    for(int i=0; i<n; i++) {
        for(j=0,k=0; j<str[i].size()&&k<temp.size(); j++,k++) {
            if(temp[k]=='[') {
                //��[]���ҵ�ƥ��
                while(temp[++k]!=']') {
                    if(match(str[i][j],temp[k])) {
                        break;
                    }
                }
                if(temp[k]==']') {
                    break;
                }
                //ƥ��֮���ҵ�]
                while(temp[k]!=']') {
                    k++;
                }
            } else {
                if(!match(str[i][j],temp[k])) {
                    break;
                }
            }
        }
        if(j==str[i].size()&&k==temp.size()) {
            cout<<i+1<<" "<<str[i]<<endl;
        }
    }
    return 0;
}
