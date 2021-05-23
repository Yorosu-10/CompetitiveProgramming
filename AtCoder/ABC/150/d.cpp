#include <bits/stdc++.h>
typedef long long ll;
typedef long long int lli;
typedef long double ld;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

// 最大公約数
long long gcd(long long a, long long b)
{
    if (a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}

// 最小公倍数
long long lcm(long long a, long long b)
{
    return a * b / gcd(a, b);
}

int main()
{
    ll N, M;
    cin >> N >> M;

    ll a0, a1;
    cin >> a0;

    ll lcm_;
    vector<ll> A(N);
    A[0] = a0;

    rep(i, N - 1)
    {
        cin >> a1;
        A[i + 1] = a1;

        lcm_ = lcm(a0, a1);
        a0 = lcm_;
    }

    bool can = true;
    ll half_lcm;
    if(lcm_%2==0){
        half_lcm = lcm_ / 2;
    }
    else
    {
        can = false;
    }

    rep(i, N){
        if(half_lcm % A[i] == 0)
            can = false;
    }

    if(can){
        ll res = (M - half_lcm) / (half_lcm * 2);
        res += 1;
        cout << res << endl;
    }else{
        cout << '0' << endl;
    }

    
    return 0;
}