#include <iostream>
#include <string>

using namespace std;

int main(){
    string W, T;
    int i, j;
    bool flag;
    int count=0;

    cin >> W;

    while(1){
        getline(cin,T);
        if(T=="END_OF_TEXT") break;

        //大文字から小文字への変換
        for(i=0;i<(int)T.size();i++)
            if(T[i]>='A'&&T[i]<='Z')T[i]+=('a'-'A');

        for(i=0;i<(int)T.size();i++){
            if(T[i]==W[0]){
                for(j=1;j<(int)W.size();j++){
                    if(T[i+j]!=W[j]) break;
                }
                if(j==(int)W.size()){
                    count++;
                }
            }
        }
    }

    cout << count << endl;

    return 0;

}