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

    vector<int> Num(N - 1);
    rep(i, 0, N - 1)
    {
        cin >> Num[i];
    }

    int ans;
    cin >> ans;

    // DP
    // dp[i][a]：i番目までの数字で計算結果がaになる場合の数
    vector<vector<ll>> dp(N+10, vector<ll>(21)); // 少し大き目に取っておく

    // DP初期条件：
    for (int a = 0; a <= 20; ++a){
        if(Num[0]==a){
            dp[0][a] = 1;
        }else{
            dp[0][a] = 0;
        }
    }

    for (int i = 0; i <= N-3; ++i)
    {
        for (int a = 0; a <= 20; ++a){
            dp[i + 1][a] = 0;
            if (0 <= (a - Num[i + 1]))
            {
                dp[i + 1][a] += dp[i][a - Num[i + 1]];
            }
            if ((a + Num[i + 1])<=20){
                dp[i + 1][a] += dp[i][a + Num[i + 1]];
            }
        }
    }

    cout << dp[N-2][ans] << endl;

    return 0;
}