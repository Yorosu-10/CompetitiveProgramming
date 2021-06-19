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
    int n, m;
    cin >> n >> m;

    vector<int> coin;

    int c;

    rep(i, 0, m){
        cin >> c;
        coin.push_back(c);
    }

    // DP
    vector<vector<int>> dp(m+5, vector<int>(n+10, INF)); // 少し大き目に取っておく

    // DP初期条件：dp[0][0]=0
    dp[0][0] = 0;

    // DPループ
    for (int i =0; i <= m; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            if(coin[i]<=j){
                dp[i + 1][j] = min(dp[i+1][j - coin[i]] + 1, dp[i][j]);
            }
            else{
                dp[i + 1][j] = dp[i][j];
            }
        }
    }

    cout << dp[m][n] << endl;

    return 0;
}