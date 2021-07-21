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
    int n;
    cin >> n;
    vector<ll> c(n); // 1次元, n個の要素
    rep(i, 0, n){
        cin >> c[i];
    }
    // vectorで昇順ソート
    sort(c.begin(), c.end());

    ll res = 1;
    rep(i, 0, n)
    {
        res *= (c[i] - i);
        res %= MOD;
    }
    cout << res << endl;

    return 0;
}