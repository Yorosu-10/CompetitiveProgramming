#include <iostream>
 
using namespace std;
 
int main(){
    int S, h, m, sec;
    cin >> S;

    h = S / 3600;
    m = (S%3600)/60;
    sec = (S%3600)%60;

    cout << h << ":" << m << ":" << sec << endl;
    return 0;
}
