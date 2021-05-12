#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
    int a, b, C;
    double S, L, h;

    cin >> a >> b >> C;

    cout << fixed << setprecision(8);

    S = a * b * sin(M_PI*C/180) / 2;

    L = a + b + sqrt(pow(a, 2.0) + pow(b, 2.0) - 2*a*b*cos(M_PI*C/180));

    h = 2 * S / a;

    cout << S << endl << L << endl <<  h << endl;

    return 0;
}