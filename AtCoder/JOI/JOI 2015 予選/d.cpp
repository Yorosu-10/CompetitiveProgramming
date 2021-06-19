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
    int M, N;
    cin >> N >> M;

    vector<int> D(N), C(M);

    rep(i, 0, N) cin >> D[i];
    rep(i, 0, M) cin >> C[i];

    // DP
    vector<vector<ll>> dp(N+1, vector<ll>(M+1, LINF));
    // DP初期条件
    rep(j, 0, M+1) dp[0][j]=0;

    rep(i, 1, N+1)
    {
        rep(j, 1, M+1)
        {
            dp[i][j] = min(dp[i][j-1], dp[i-1][j-1] + C[j-1]*D[i-1]);
        }
    }

    ll res = LINF;
    //さらに最小の答えを探す
    rep(j, 0, M+1)
    {
        res = min(res, dp[N][j]);
    }

    cout << res << endl;

    return 0;
}