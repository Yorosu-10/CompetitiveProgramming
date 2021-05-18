#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main()
{
    string N;
    cin >> N;
    ll K;
    cin >> K;

    // f()をK回繰り返す
    rep(i, K){
        string N1 = N;
        string N2 = N;
        sort(N2.begin(), N2.end());
        sort(N1.rbegin(), N1.rend());
        N = to_string(stoll(N1) - stoll(N2));
    }

    cout << N << endl;

    return 0;
}