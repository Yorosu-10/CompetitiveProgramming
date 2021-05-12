#include <iostream>
#include <string>

using namespace std;

int main(){
    string W, T;

    int count=0;

    cin >> W;

    //大文字から小文字への変換
    for(int i=0;i<(int)W.size();i++)
        if(W[i]>='A'&&W[i]<='Z')W[i]+=('a'-'A');

    while(cin >> T){
        if(T=="END_OF_TEXT") break;

        //大文字から小文字への変換
        for(int i=0;i<(int)T.size();i++)
            if(T[i]>='A'&&T[i]<='Z')T[i]+=('a'-'A');

        if(W==T) count++;

    }

    cout << count << endl;

    return 0;

}