#include <bits/stdc++.h>
typedef long long ll;
typedef long long int lli;
typedef long double ld;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

// a^n mod を計算する  // https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a#4-%E7%B4%AF%E4%B9%97-an
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

ll ModRoadLength(ll c_start, ll c_end, vector<ll> toCity_mod)
{
    ll r = 0;

    if (c_start > c_end)
        swap(c_start, c_end);

    r += (toCity_mod[c_end]-toCity_mod[c_start]);
    // r %= 1000000007;
    
    return r;
}

int main()
{
    ll N,Q,a;
    cin >> N >> Q;

    // [i]は街iを指すものとする。
    vector<ll> A(N);

    rep(i, N){
        cin >> A[i];
    }

    // [i]は街i-1<->iの間の道を指すものとする。
    vector<ll> Road_mod(N - 1);

    rep(i, N-1){
        Road_mod[i] = modpow(A[i],A[i+1], 1000000007);
    }

    // [i]は街i-1->iの間の道を指すものとする。
    vector<ll> toCity_mod(N);
    toCity_mod[0] = 0;
    for (int i = 1; i < N; ++i)
    {
        toCity_mod[i] = toCity_mod[i-1] + Road_mod[i-1];
    }

    ll c_start = 0, c_end;

    ll res = 0;

    rep(i, Q){
        cin >> c_end;
        c_end -= 1;

        res += (toCity_mod[max(c_start, c_end)] - toCity_mod[min(c_start, c_end)]);
        res %= 1000000007;

        // res += ModRoadLength(c_start, c_end, toCity_mod);

        c_start = c_end;
    }

    c_end = 0;

    res += (toCity_mod[max(c_start, c_end)] - toCity_mod[min(c_start, c_end)]);

    // res += ModRoadLength(c_start, c_end, toCity_mod);
    res %= 1000000007;

    cout << res << endl;

    return 0;
}