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

    rep(i, 0, N){
        cin >> Cloth[i][0] >> Cloth[i][1] >> Cloth[i][2];
    }

    // DP
    vector<vector<vector<int>>> dp(D, vector<vector<int>>(N, vector<int>(N, 0)));

    int yesterday_max = 0;
    int tmp = 0;
    rep(i, 0, D - 1)
    {
        rep(j0, 0, N){
            rep(j1, 0, N){
                if (Cloth[j0][0] <= T[i] && T[i] <= Cloth[j0][1] && Cloth[j1][0] <= T[i+1] && T[i+1] <= Cloth[j1][1]){
                    dp[i + 1][j0][j1] = abs(Cloth[j0][2] - Cloth[j1][2]) + yesterday_max;
                }
                else
                {
                    // dp[i + 1][j0][j1] = 0;
                }
                tmp = max(tmp, dp[i + 1][j0][j1]);
            }
        }
        yesterday_max = tmp;
    }

    cout << yesterday_max << endl;

    return 0;
}