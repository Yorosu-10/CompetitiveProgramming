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

// DPテーブル
bool dp[110][100010];

int main()
{
    int n;
    cin >> n;
    vector<int> a(n); // 1次元, 要素数指定なし
    int t;
    int sum = 0;
    rep(i, 0, n)
    {
        cin >> t;
        a[i] = t;
        sum += t;
    }

    memset(dp, 0, sizeof(dp));   // 一旦すべて false に
    dp[0][0] = true;             // dp[0][0] だけ true に

    int res = INF;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= 1e5+1; ++j) {
            dp[i+1][j] |= dp[i][j];
            if (j >= a[i]) dp[i+1][j] |= dp[i][j-a[i]];
            if (j >= (sum + 1) / 2 && dp[i + 1][j])
                res = min(res, j);
        }
    }

    cout << res << endl;

    return 0;
}