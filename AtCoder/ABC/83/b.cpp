#include <iostream>
#include <string>      // string
#include <algorithm>   // min, max, swap
#include <iomanip>　   // setprecision()
#include <cmath>　　　 // pow, sqrt
#include <vector>      // vector

using namespace std;

int main()
{
    int N, A, B;
    cin >> N >> A >> B;

    // Nの万, 千, 百, 十, 一の位
    int n4, n3, n2, n1, n0;

    int sum = 0;
    int m;

    for(int nn=1; nn<=N; nn++){
        n4 = nn / 10000;
        n3 = (nn - n4 * 10000) / 1000;
        n2 = (nn - n4 * 10000 - n3 * 1000) / 100;
        n1 = (nn - n4 * 10000 - n3 * 1000 - n2 * 100) / 10;
        n0 = nn - n4 * 10000 - n3 * 1000 - n2 * 100 - n1 * 10;

        m = n0 + n1 + n2 + n3 + n4;

        if (A<=m && m<=B){
            sum = sum + nn;
        }
    }

    cout << sum << endl;

    return 0;
}