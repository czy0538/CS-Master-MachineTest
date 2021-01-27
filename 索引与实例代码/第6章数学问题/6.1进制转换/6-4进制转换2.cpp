#include<iostream>
#include<string>
#include<vector>

using namespace std;

//����ת�ַ�
char int2char(int x) {
    if(x<10) {
        return x+'0';
    } else {
        return x-10+'a';
    }
}

//�ַ�ת����
int char2int(char x) {
    if(x>='0'&&x<='9') {
        return x-'0';
    } else {
        return x-'A'+10;
    }
}

int main() {
    string str;
    int m,n;
    while(scanf("%d%d",&m,&n)!=EOF) {
        cin>>str;
        long long int number=0;
        for(int i=0; i<str.size(); i++) {
            number=m*number+char2int(str[i]);
        }
        vector<int> answer;
        while(number!=0) {
            answer.push_back(number%n);
            number=number/n;
        }

        for(int i=answer.size()-1; i>=0; i--) {
            cout<<answer[i];
        }
        cout<<endl;
    }
    return 0;
}

