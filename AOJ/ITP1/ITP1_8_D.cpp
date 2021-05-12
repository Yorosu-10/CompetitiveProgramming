#include <iostream>
#include <string>

using namespace std;

int main(){
    string s, p;
    cin >> s >> p;

    int i, j ,k;

    bool flag=false;

    for(i=0;i<(int)s.size();i++){
        if(s[i]==p[0]){
            for(j=1;j<(int)p.size();j++){
                if(i+j>(int)s.size()-1){
                    k=i+j-(int)s.size();
                }else{
                    k=i+j;
                }

                if(s[k]!=p[j]) break; 
            }
            if(j==(int)p.size()){
                flag=true;
                break;
            } 
        }
    }

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;

}