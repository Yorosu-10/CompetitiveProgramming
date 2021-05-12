#include <iostream>

using namespace std;

int main(){
    string S;
    cin >> S;

    int c=0;

    for(int i=0; i<12; i++){
        if(S[i]=='Z'){
            if(S[i+1]=='O'&&i+1<12){
                if(S[i+2]=='N'&&i+2<12){
                    if(S[i+3]=='e'&&i+3<12){
                        c=c+1;
                    }
                }
            }
        }
    }

    cout << c << endl;

    return 0;
}