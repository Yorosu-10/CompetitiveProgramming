#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main(){
    string str;

    //空白も含めて1行まるごとを文字列として受け取るためにはgetline関数を使う
    getline(cin,str);

    for(int i=0;i<(int)str.size();i++){
        // 小文字->大文字
        if('a'<=str[i]&&str[i]<='z'){
            str[i]=str[i]+('A'-'a');
        // 大文字->小文字
        }else if('A'<=str[i]&&str[i]<='Z'){
            str[i]=str[i]-('A'-'a');
        }
    }

    cout<<str<<endl;

    return 0;

}