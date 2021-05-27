#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const double PI = acos(-1);
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<ll> L(n - 1);
    rep(i, n - 1) cin >> L[i];

    // 累積和 // [0]は0を代入
    vector<ll> Sum_L(n, 0);
    for (int i = 1; i <= n;++i){
        Sum_L[i] = Sum_L[i-1] + L[i - 1];
    }

    ll res = 0;

    int a;

    int now = 0;
    int next;

    rep(i,m){
        cin >> a;
        next = now + a;
        res += abs(Sum_L[next] - Sum_L[now]);
        res %= 100000;
        now = next;
    }

    cout << res << endl;

    return 0;
}