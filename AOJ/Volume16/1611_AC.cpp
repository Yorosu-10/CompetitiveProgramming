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
    int n;
    while (cin >> n && n!=0)
    {
        vector<int> w(n); // 1次元, n個の要素
        rep(i, 0, n) cin >> w[i];

        vector<vector<int>> dp(n, vector<int>(n,0)); // 2次元, n行m列

        rep(d,1,n){
            rep(i, 0, n-d){
                int j = i + d;
                // 間のブロックを叩き出せる場合
                // 両端のブロックの重さの差が1以下
                if (dp[i + 1][j - 1] == d - 1 && abs(w[i] - w[j]) <= 1)
                    dp[i][j] = d+1;

                // 区切るブロックを全て試す
                for (int k = i; k < j; ++k)
                {
                    dp[i][j] = max(dp[i][j], dp[i][k]+dp[k+1][j]);
                }
            }
        }
        cout << dp[0][n - 1] << endl;
    }

    return 0;
}