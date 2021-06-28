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
    int n;
    cin >> n;

    vector<int> r(n), c(n);

    rep(i, 0, n){
        cin >> r[i] >> c[i];
    }

    // DP
    vector<vector<ll>> dp(n, vector<ll>(n, LINF));
    // DP初期条件
    rep(i, 0, n){
        dp[i][i] = 0;
    }

    rep(d, 1, n){
        rep(i, 0, n-d){
            int j = i + d;
            for (int k = i; k < j; ++k)
            {
                // cost(左側行列積) + cost(右側行列積) + 行列計算のコスト
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]+r[i]*c[k]*c[j]);
            }
        }
    }

    cout << dp[0][n - 1] << endl;

    return 0;
}