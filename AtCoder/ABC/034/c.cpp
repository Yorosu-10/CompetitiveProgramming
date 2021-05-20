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
long long kaijo_mod(long long a, long long m){

    long long res = 1;
    for (int i = 1; i <= a; ++i)
    {
        res *= i;
        res %= m;
    }

    return res;
}

int main()
{
    ll W, H;
    cin >> W >> H;
    W -= 1;
    H -= 1;

    ll mod = 1000000007;

    // (W+H)C(W) = (W+H)!/W!H! の modを求めればよい
    // W!, H!は逆元を求める必要あり。

    ll WH_kaijo = kaijo_mod(W + H, mod);
    ll W_kaijo = kaijo_mod(W, mod);
    ll H_kaijo = kaijo_mod(H, mod);

    ll gyaku_W_kaijo = modinv(W_kaijo, mod);
    ll gyaku_H_kaijo = modinv(H_kaijo, mod);

    ll res = WH_kaijo * gyaku_H_kaijo;
    res %= mod;
    res = res * gyaku_W_kaijo;
    res %= mod;

    cout << res << endl;

    return 0;
}