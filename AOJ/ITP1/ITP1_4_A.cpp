#include <iostream>
#include <iomanip>

using namespace std;
 
int main(){
    int a, b, d, r;
    double f;

    cin >> a >> b;

    d = a/b;
    r = a%b;
    f = static_cast<double>(a)/b;

    cout << fixed << setprecision(5);
    cout << d << " " << r << " " << f << endl;
}