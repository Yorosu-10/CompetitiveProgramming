#include <iostream>
#include <string>      // string
#include <algorithm>   // min, max, swap
#include <iomanip>　   // setprecision()
#include <cmath>　　　 // pow, sqrt
#include <vector>      // vector
using namespace std;

int main()
{
    long long int N;
    cin >> N;
    
    vector<long long int> A(N);
    for (long long int i = 0; i < N; ++i){
        cin >> A[i];
    }

    // bakket
    vector<long long int> Rem(200, 0);

    int r;
    for (long long int i = 0; i < N; ++i){
        r = A[i] % 200;
        Rem[r]++;
    }

    long long int res=0;

    for (r = 0; r < 200; ++r){
        if(Rem[r]!=0)
            res +=  Rem[r] * (Rem[r] - 1) / 2;
    }

    cout << res << endl;

    return 0;
}
