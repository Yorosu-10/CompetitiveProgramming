#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    vector<int> alphabet_count(26);
    for(int i=0; i<26; i++){
        alphabet_count[i]=0;
    }

    while(1){
        string str;
        //空白も含めて1行まるごとを文字列として受け取るためにはgetline関数を使う
        getline(cin,str);
        //標準入力がなくなったときブレーク
        if(cin.eof()) break;

        for(int i=0;i<(int)str.size();i++){
            for(int ab=0;ab<26;ab++){
                if(str[i]=='a'+ab || str[i]=='A'+ab) alphabet_count[ab]++;
            }
        }
    }

    for(int ab=0;ab<26;ab++){
        // charでキャストしないとintで出力される
        cout << char('a'+ab) << " : " << alphabet_count[ab] << endl;
    }

    return 0;

}