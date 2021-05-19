#include <bits/stdc++.h>
typedef long long ll;
typedef long long int lli;
typedef long double ld;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main()
{
    ll A, B, K;
    cin >> A >> B >> K;

    if (K <= A)
    {
        cout << (A - K) << " " << B << endl;
    }else{
        if(0<=(A+B-K))
            cout << '0' << " " << (A+B-K) << endl;
        else
            cout << '0' << " " << '0' << endl;
    }

    return 0;
}