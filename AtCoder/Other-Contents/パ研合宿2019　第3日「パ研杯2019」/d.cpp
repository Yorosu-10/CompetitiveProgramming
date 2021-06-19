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

    vector<vector<int>> S(5, vector<int>(N)); // 2次元, n行m列

    // 色：B->0, W->1, R->2, #->3
    string str;
    rep(i, 0, 5)
    {
        cin >> str;
        rep(j, 0, N){
            if (str[j] == 'B')
                S[i][j] = 0;
            if (str[j] == 'W')
                S[i][j] = 1;
            if (str[j] == 'R')
                S[i][j] = 2;
            if (str[j] == '#')
                S[i][j] = 3;
        }
    }

    // DP
    // dp[i列目][i列目の色]="塗り替えの最小数"
    // 色：B->0, W->1, R->2, #->3
    vector<vector<ll>> dp(N+10, vector<ll>(3, 0)); // 2次元, n行m列

    // DP初期条件
    // 0列目について
    rep(i,0,5){
        if(S[i][0]==0){
            ++dp[0][0];
        }
        else if (S[i][0] == 1)
        {
            ++dp[0][1];
        }
        else if (S[i][0] == 2)
        {
            ++dp[0][2];
        }
    }
    rep(color, 0, 3){
        dp[0][color] = 5 - dp[0][color];
    }
    
    // DPループ
    rep(i, 1, N){
        rep(color, 0, 3)
        {
            //i列目をcolorで塗るのに必要なマスの個数
            rep(r, 0, 5){
                if(S[r][i]!=color){
                    dp[i][color]++;
                }
            }
            ll tmp=LINF;
            rep(color_, 0, 3){
                if(color==color_)
                    continue;
                tmp = min(tmp, dp[i - 1][color_]);
            }
            dp[i][color] += tmp;
        }
    }

    ll res = LINF;
    rep(color, 0, 3){
        res = min(res, dp[N-1][color]);
    }

    cout << res << endl;

    return 0;
}