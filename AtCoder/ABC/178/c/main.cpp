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

// aのn乗(a^n) mod を計算する  // https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a#4-%E7%B4%AF%E4%B9%97-an
long long modpow(long long a, long long n, long long mod)
{
    long long res = 1;
    while (n > 0)
    {
        if (n & 1)
            res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main()
{
    int N;
    cin >> N;

    ll res = modpow(10, N, MOD) + modpow(8, N, MOD) - modpow(9, N, MOD) - modpow(9, N, MOD);
    res %= MOD;
    res = (res + MOD) % MOD;

    cout << res << endl;

    return 0;
}