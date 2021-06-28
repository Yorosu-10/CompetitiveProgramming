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
    vector<string> S(N);
    rep(i, 0, N) cin >> S[i];

    vector<vector<ll>> dp(N+10, vector<ll>(2)); // 2次元, n行m列
    // 初期条件
    dp[0][0] = 1;
    dp[0][1] = 1;

    rep(i, 0, N){
        if(S[i]=="AND"){
            dp[i + 1][0] = 2 * dp[i][0] + dp[i][1];
            dp[i + 1][1] = dp[i][1];
        }
        else
        {
            dp[i + 1][0] = dp[i][0];
            dp[i + 1][1] = 2 * dp[i][1] + dp[i][0];
        }
    }

    cout << dp[N][1] << endl;
    return 0;
}