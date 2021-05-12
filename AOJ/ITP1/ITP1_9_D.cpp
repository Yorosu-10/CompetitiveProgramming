#include <iostream>
#include <string>

using namespace std;

int main(){

    string str, str_tmp;
    int q;

    cin >> str;
    cin >> q;

    str_tmp = str;

    string command, p;
    int a, b;

    for(int i=0; i<q; i++){
        cin >> command >> a >> b;
        if(command=="print"){
            for(int j=a; j<=b; j++){
                cout << str[j];
            }
            cout << endl;
        }else if(command=="reverse"){
            for(int j=a; j<=b; j++){
                str_tmp[j-a]=str[j];
            }
            for(int j=a; j<=b; j++){
                str[j]=str_tmp[b-j];
            }
        }else if(command=="replace"){
            cin >> p;
            for(int j=a; j<=b; j++){
                str[j]=p[j-a];
            }
        }else{}
    }

    return 0;

}