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
    int N;
    cin >> N;

    vector<ll> a(N);
    rep(i, 0, N){
        cin >> a[i];
    }

    // 累積和
    vector<ll> sum_a(N+1, 0);
    rep(i, 1, N+1){
        sum_a[i] = sum_a[i - 1] + a[i - 1];
    }

    // aのi項目までの最大値を格納した配列
    vector<ll> max_sum_a(N + 1);
    max_sum_a[0] = sum_a[0];
    rep(i, 1, N + 1)
    {
        max_sum_a[i] = max(max_sum_a[i - 1], sum_a[i]);
    }

    // 累積和の累積和をとる。
    vector<ll> sum_sum_a(N + 1);
    sum_sum_a[0] = sum_a[0];
    rep(i, 1, N + 1){
        sum_sum_a[i] = sum_a[i] + sum_sum_a[i - 1];
    }

    ll res = 0;
    rep(i, 0, N){
        res = max(sum_sum_a[i] + max_sum_a[i], res);
    }
    res = max(sum_sum_a[N], res);

    cout << res << endl;

    return 0;
}