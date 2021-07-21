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
long long mod_kaijo(long long a, long long m)
{

    long long res = 1;
    for (int i = 1; i <= a; ++i)
    {
        res *= i;
        res %= m;
    }

    return res;
}

// nCr modの計算
long long mod_nCr(long long n, long long r, long long m)
{
    // nCr = n!/r!(n-r)! のmodを求める。
    // r!, (n-r)!は逆元を求める必要あり。
    ll n_kaijo = mod_kaijo(n, m);
    ll r_kaijo = mod_kaijo(r, m);
    ll nr_kaijo = mod_kaijo(n - r, m);

    ll gyaku_r_kaijo = modinv(r_kaijo, m);
    ll gyaku_nr_kaijo = modinv(nr_kaijo, m);

    ll res = n_kaijo * gyaku_r_kaijo;
    res %= m;
    res = res * gyaku_nr_kaijo;
    res %= m;

    return res;
}

int main()
{
    int S;
    cin >> S;

    int max_num = S / 3;

    ll res = 0;
    for (int n = 1; n <= max_num; ++n)
    {
        int rem = S - (n*3);
        res += mod_nCr(rem+n-1, rem, MOD);
        res %= MOD;
    }

    cout << res << endl;
    return 0;
}