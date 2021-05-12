#include <iostream>
#include <string>

using namespace std;

// 文字->'X', 文字列->"X"

int main(){
    while(1){
        string str;
        cin>>str;

        if(str=="0"){
            break;
        }
        int sum=0;
        for(int i=0;i<(int)str.size();i++){
            // 0~9の文字列から0~9の値を取得
            sum+=str[i]-'0';
        }

    cout<<sum<<endl;
    }
    return 0;
}
