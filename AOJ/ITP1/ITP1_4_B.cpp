#include <iostream>
#include <iomanip>
#include <math.h>  /* M_PI */

using namespace std;
 
int main(){
    cout << fixed << setprecision(6);

    double r;
    cin >> r;

    cout << r*r*M_PI << " " << 2*r*M_PI << endl;

    return 0;
}