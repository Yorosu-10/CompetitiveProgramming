#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

int main(){
    cout << fixed << setprecision(8);

    while(1){
        int n;
        cin >> n;

        if(n==0) break;

        vector<int> s(n);

        double m=0, sigma=0;

        for(int i=0; i<n; i++){
            cin >> s[i];
            m+=s[i];
        }

        m = m / n;

        for(int i=0; i<n; i++){
            sigma += pow(s[i]-m, 2.0);
        }
        sigma = sqrt(sigma/n);
        
        cout << sigma << endl;
    }
    
    return 0;
}
