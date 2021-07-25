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
    string S;
    cin >> S;
    
    // row -> chokudai
    // column -> 〇文字目、0始まり
    vector<vector<long long >> dp(8, vector<long long>((int)S.size(), 0)); // 2次元, n行m列

    // dp初期条件：
    if(S[0]=='c')
        dp[0][0] = 1;

    // dpループ
    for (int i = 1; i < (int)S.size(); ++i)
    {
        if(S[i]=='c'){
            dp[0][i] = dp[0][i - 1] + 1;
        }else{
            dp[0][i] = dp[0][i - 1];
        }
        if (S[i] == 'h'){
            dp[1][i] = dp[0][i - 1]+dp[1][i - 1];
        }else{
            dp[1][i] = dp[1][i - 1];
        }
        if (S[i] == 'o'){
            dp[2][i] = dp[1][i - 1] + dp[2][i - 1];
        }else{
            dp[2][i] = dp[2][i - 1];
        }
        if (S[i] == 'k')
        {
            dp[3][i] = dp[2][i - 1] + dp[3][i - 1];
        }else{
            dp[3][i] = dp[3][i - 1];
        }
        if (S[i] == 'u'){
            dp[4][i] = dp[3][i - 1] + dp[4][i - 1];
        }else{
            dp[4][i] = dp[4][i - 1];
        }
        if (S[i] == 'd'){
            dp[5][i] = dp[4][i - 1] + dp[5][i - 1];
        }else{
            dp[5][i] = dp[5][i - 1];
        }
        if (S[i] == 'a')
        {
            dp[6][i] = dp[5][i - 1] + dp[6][i - 1];
        }else{
            dp[6][i] = dp[6][i - 1];
        }
        if (S[i] == 'i'){
            dp[7][i] = dp[6][i - 1] + dp[7][i - 1];
        }else{
            dp[7][i] = dp[7][i - 1];
        }

        rep(j, 0, 7)
            dp[j][i] %= MOD;
    }

    cout << dp[7][(int)S.size() - 1] << endl;

    return 0;
}