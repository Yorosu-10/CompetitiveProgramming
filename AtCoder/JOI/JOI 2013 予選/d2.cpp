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
    int D, N;
    cin >> D >> N;

    vector<int> T(D); // 1次元, n個の要素
    rep(i, 0, D) cin >> T[i];

    vector<vector<int>> Cloth(N, vector<int>(3)); // 2次元, n行m列

    rep(i, 0, N)
    {
        cin >> Cloth[i][0] >> Cloth[i][1] >> Cloth[i][2];
    }

    // DP
    vector<vector<int>> dp(D, vector<int>(N, 0));

    rep(j, 0, N){
        if (Cloth[j][0] > T[0] || T[0] > Cloth[j][1])
        {
            dp[0][j] = -INF;
        }
    }

    rep(i, 0, D - 1)
    {
        rep(j, 0, N){
            if (Cloth[j][0] > T[i+1] || T[i+1] > Cloth[j][1]){
                dp[i + 1][j] = -INF;
            }
            else{
                rep(k, 0, N)
                {
                    dp[i + 1][j] = max(dp[i + 1][j], dp[i][k] + abs(Cloth[j][2] - Cloth[k][2]));
                }
            }
        }
    }

    int res = -INF;

    rep(j, 0, N){
        res = max(res, dp[D-1][j]);
    }

    cout << res << endl;

    return 0;
}