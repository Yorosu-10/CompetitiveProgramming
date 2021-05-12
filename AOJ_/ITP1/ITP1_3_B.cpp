#include <iostream>
 
using namespace std;
 
int main(){
    int x;
    for(int i=1; i<=10000; i++){
        cin >> x;
        if(x==0){
            break;
        }else{
            cout << "Case "<< i << ": " << x << endl;
        }
    }
    return 0;
}
