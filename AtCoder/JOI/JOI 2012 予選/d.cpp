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
    int N, K;
    cin >> N >> K;

    // DP
    vector<vector<vector<int>>> dp(N+10, vector<vector<int>>(3, vector<int>(3, INF)));

    // DP初期条件：dp[0][0~2][0~2] = 1
    // DP初期条件：dp[1][0~2][0~2] = 1
    rep(j, 0, 3){
        rep(k, 0, 3){
            dp[0][j][k] = 1;
            dp[1][j][k] = 1;
        }
    }


    // DP初期条件：dp[A][0~2][!=B] = 0
    int A, B;
    rep(i, 0, K)
    {
        cin >> A >> B;
        --A;
        --B;
        rep(j, 0, 3)
        {
            rep(k, 0, 3)
            {
                if (B != k)
                {
                    dp[A][j][k] = 0;
                }
                if(B!=j){
                    dp[A + 1][j][k] = 0;
                }
            }
        }
    }

    for (int i = 1; i < N + 5; ++i)
    {
        rep(j, 0, 3){
            rep(k, 0, 3){
                if(dp[i+1][j][k]==0){
                    continue;
                }
                if(j!=k){
                    dp[i+1][j][k] = dp[i][0][j] + dp[i][1][j] + dp[i][2][j];
                }
                else
                {
                    if(j==0){
                        dp[i + 1][j][k] = dp[i][1][j] + dp[i][2][j];
                    }
                    else if (j == 1)
                    {
                        dp[i + 1][j][k] = dp[i][2][j] + dp[i][0][j];
                    }
                    else if (j == 2)
                    {
                        dp[i + 1][j][k] = dp[i][0][j] + dp[i][1][j];
                    }
                }
                dp[i + 1][j][k] %= 10000;
            }
        }
    }

    int res = 0;

    rep(j, 0, 3){
        rep(k, 0, 3){
            res += dp[N - 1][j][k];
        }
    }

    res %= 10000;
    cout << res << endl;

    return 0;
}