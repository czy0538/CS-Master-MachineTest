#include<iostream>
#include<string>
using namespace std;
//�Ƿ���Сд��ĸ
bool ischar(char x) {
    if(x>='a'&&x<='z') {
        return true;
    }
    return false;
}

int main() {
    string str;
    while(getline(cin,str)) {
        if(ischar(str[0])) {
            cout<<(char)(str[0]-'a'+'A');
        } else {
            cout<<(char)str[0];
        }

        bool isblank=false;//�հ׷��ָ����
        for(int i=1; i<str.size(); i++) {
            if(str[i]==' '||str[i]=='\t'||str[i]=='\r'||str[i]=='\n') {
                isblank=true;
                cout<<str[i];
            } else if(isblank&&ischar(str[i])) {
                cout<<(char)(str[i]-'a'+'A');
                isblank=false;
            } else {
                cout<<str[i];
                isblank=false;
            }
        }
    }
    return 0;
}
