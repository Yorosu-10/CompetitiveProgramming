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
    int N, M;
    while (cin >> N >> M)
    {
        if(N==0 && M==0)
            break;
            
        vector<int> C(M);
        rep(i, 0, M)
        {
            cin >> C[i];
        }
        vector<int> x(N);
        rep(i, 0, N)
        {
            cin >> x[i];
        }

        vector<vector<ll>> dp(20010, vector<ll>(256, INF)); // 2次元, n行m列
        // DP初期条件
        dp[0][128] = 0;

        int y1;

        rep(i, 1, 20005)
        {
            rep(y, 0, 256)
            {
                ll tmp = INF;
                if (y == 0)
                {
                    rep(m, 0, M)
                    {
                        if (C[m] <= 0)
                        {
                            for (int j = 0; j <= -C[m]; ++j)
                            {
                                tmp = min(tmp, dp[i - 1][j]);
                            }
                        }
                    }
                }
                else if (y == 255)
                {
                    rep(m, 0, M)
                    {
                        if (C[m] >= 0)
                        {
                            for (int j = 255 - C[m]; j <= 255; ++j)
                            {
                                tmp = min(tmp, dp[i - 1][j]);
                            }
                        }
                    }
                }
                else
                {
                    rep(m, 0, M)
                    {
                        y1 = y - C[m];
                        if (y1 < 0 || 255 < y1)
                        {
                            break;
                        }
                        else
                        {
                            tmp = min(tmp, dp[i - 1][y1]);
                        }
                    }
                }
                dp[i][y] = (y - x[i - 1]) * (y - x[i - 1]);
                dp[i][y] += tmp;
            }
        }

        ll res = INF;
        rep(y, 0, 256)
        {
            res = min(res, dp[N][y]);
        }
        cout << res << endl;
    }

    return 0;
}