#include <iostream>
#include <algorithm>
 
using namespace std;
 
int main(){
    int i, x, y;

    for(i=0; i<3000; i++){
        cin >> x >> y;

        if(x==0 && y==0) break;
        else{
            if(x>y) swap(x,y);
            cout << x << " " << y << endl;
        } 

    }
    return 0;
}
