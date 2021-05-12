#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

int main(){
    cout << fixed << setprecision(6);

    int n;
    cin >> n;

    vector<int> x(n), y(n);
    vector<double> Distance(4);

    for(int i=0; i<n; i++){
        cin >> x[i];
    }

    for(int i=0; i<n; i++){
        cin >> y[i];
    }

    int d;
    Distance[3] = 0;

    for(int i=0; i<n; i++){
        d = abs(x[i]-y[i]);
        Distance[0] += d;
        Distance[1] += pow(d, 2.0);
        Distance[2] += pow(d, 3.0);
        if(d>Distance[3]) Distance[3] = d;
    }

    Distance[1] = pow(Distance[1], 1.0/2);
    Distance[2] = pow(Distance[2], 1.0/3);

    cout << Distance[0] << endl << Distance[1] << endl << Distance[2] << endl<< Distance[3] << endl;
    
    return 0;
}
