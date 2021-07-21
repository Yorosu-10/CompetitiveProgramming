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
    ll P;
    cin >> P;

    vector<ll> coin(10, 1);
    rep(i, 1, 10){
        coin[i] = coin[i - 1] * (i + 1);
    }

    int res = 0;
    for (int i = 9; i >= 0; --i)
    {
        res += (P / coin[i]);
        P = P % coin[i];
    }

    cout << res << endl;
    return 0;
}