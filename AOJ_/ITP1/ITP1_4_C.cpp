#include <iostream>

using namespace std;
 
int main(){
    int a, b;
    char op;
    
    while(1){
        cin >> a >> op >> b;

        if(op=='?') break;
        else if(op=='+') cout << a+b << endl;
        else if(op=='-') cout << a-b << endl;
        else if(op=='*') cout << a*b << endl;
        else if(op=='/') cout << a/b << endl;
        else break;

    }

    return 0;
}