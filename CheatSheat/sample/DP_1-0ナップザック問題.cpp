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
    int N, W;
    cin >> N >> W;

    vector<int> value;
    vector<int> weight;

    int tmp_v, tmp_w;

    rep(i, 0, N){
        cin >> tmp_v >> tmp_w;
        value.push_back(tmp_v);
        weight.push_back(tmp_w);
    }

    // DP
    vector<vector<int>> dp(N+10, vector<int>(W+10)); // 少し大き目に取っておく

    // DP初期条件：dp[0][j]=0
    for(int w = 0; w <= W; ++w) dp[0][w] = 0;

    // DPループ
    for (int i = 0; i < N; ++i)
    {
        for (int w = 0; w <= W;++w)
        {
            if(weight[i]<=w){
                dp[i + 1][w] = max(dp[i][w - weight[i]] + value[i], dp[i][w]);
            }
            else{
                dp[i + 1][w] = dp[i][w];
            }
        }
    }

    cout << dp[N][W] << endl;

    return 0;
}