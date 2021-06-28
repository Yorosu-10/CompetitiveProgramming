#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
#define rep(i, b, e) for (int i = (int)(b); i < (int)(e); i++)
const double PI = acos(-1);
using namespace std;
using Graph = vector<vector<int>>;

int main()
{
    int N;
    cin >> N;

    vector<ll> A(N); // 1次元, n個の要素

    rep(i, 0, N){
        cin >> A[i];
    }

    sort(A.rbegin(), A.rend());

    ll res = 0;
    rep(i, 0, N)
    {
        res += (N - 1 - 2 * i) * A[i];
    }

    cout << res << endl;

    return 0;
}