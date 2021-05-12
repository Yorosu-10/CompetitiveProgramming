#include <iostream>
 
using namespace std;
 
int main(){
    int a, b, c;
    int count = 0;

    cin >> a >> b >> c;

    for(int n=a; n<=b; n++){
        if(c%n == 0) count++;
    }

    cout << count << endl;

    return 0;
}
