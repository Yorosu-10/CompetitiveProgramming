#include <iostream>
#include <string>

using namespace std;

int main(){
    string card;
    int m; // シャッフル回数

    while(cin>>card){
        if(card=="-") break;

        cin >> m;

        int n=(int)card.size(); //カード枚数

        //下のように書くと後でコンパイルエラー
        //char型に変換されてしまうみたい
        //string tmp[200];
        //string tmp[200];
        string tmp=card;
        int h;

        for(int i=0; i<m; i++){
            cin >> h;
            for(int j=0; j<h; j++) tmp[j]=card[j];
            for(int j=0; j<n; j++){
                if(j<n-h) card[j]=card[j+h];
                else card[j]=tmp[j-(n-h)];
            }
        }

        cout << card << endl;
    }
    return 0;

}