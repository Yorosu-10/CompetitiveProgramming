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
    int N;
    cin >> N;

    vector<int> A(N), B(N), C(N);

    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];
    rep(i, N) cin >> C[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    // BのN個の要素について、
    // 各要素ごとにそれ以上の値のCの要素がいくつあるか配列として持っておく。
    vector<int> B_cnt(N);

    rep(i, N){
        auto IterC = lower_bound(C.begin(), C.end(), B[i]);
        B_cnt[i] = C.end() - IterC;
    }

    // 累積和を持っておく。
    // 要素[i]はi~NのB_cntの和
    vector<int> B_sum(N, 0);
    B_sum[N-1] = B_cnt[N-1];
    for (int i = N - 2; i >= 0;--i)
    {
        B_sum[i] = B_sum[i+1] + B_cnt[i];
    }

    ll res = 0;
    rep(i, N)
    {
        auto IterB = lower_bound(B.begin(), B.end(), A[i]);
        if(IterB==B.end())
            continue;
        int IndexB = IterB - B.begin();
        res += B_sum[IndexB];
    }

    cout << res << endl;

    return 0;
}