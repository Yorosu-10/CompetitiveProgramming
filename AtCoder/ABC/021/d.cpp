#include <bits/stdc++.h>
typedef long long ll;
typedef long long int lli;
typedef long double ld;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

// aのmod mでの逆元を求める
// mod mでのaの逆元が存在する条件は、mとaとが互いに素であること
long long modinv(long long a, long long m)
{
    long long b = m, u = 1, v = 0;
    while (b)
    {
        long long t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= m;
    if (u < 0)
        u += m;
    return u;
}

// a!のmod mを求める
long long kaijo_mod(long long a, long long m)
{
    long long res = 1;
    for (int i = 1; i <= a; ++i)
    {
        res *= i;
        res %= m;
    }

    return res;
}

// nCrのmod mを求める。
// !注意! modinv()とkaijo_mod()が必要
long long nCr_mod(long long n, long long r, long long mod){
    long long n_kaijo = kaijo_mod(n, mod);
    long long r_kaijo = kaijo_mod(r, mod);
    long long n_r_kaijo = kaijo_mod(n - r, mod);

    long long gyaku_r_kaijo = modinv(r_kaijo, mod);
    long long gyaku_n_r_kaijo = modinv(n_r_kaijo, mod);

    long long res = n_kaijo * gyaku_r_kaijo;
    res %= mod;
    res = res * gyaku_n_r_kaijo;
    res %= mod;

    return res;
}

int main()
{
    ll n, k;
    cin >> n >> k;

    ll res = 0;
    ll mod = 1000000007;

    /* TLEしてしまう */
    /* 
    for (ll i = max(ll(0), (k - n)); i <= k-1;++i){
        ll nCr = nCr_mod(n, k - i, mod);
        ll kCi = nCr_mod(k-1, i, mod);
        res += nCr * kCi;
        res %= mod;
    }
    */

    // 重複組み合わせ
    // n個の数字から重複を許してk個選ぶ
    res = nCr_mod(n+k-1, k, mod);

    cout << res << endl;

    return 0;
}