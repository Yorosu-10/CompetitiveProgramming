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
    int R, C;
    cin >> R >> C;

    vector<vector<int>> senbei_init(R, vector<int>(C));
    rep(r, 0, R){
        rep(c ,0, C){
            cin >> senbei_init[r][c];
        }
    }

    int res = 0;
    // どの行を裏返すのかビット全探索
    for (int bit = 0; bit < (1 <<R); ++bit)
    {
        auto senbei = senbei_init;
        int rev = 0;
        for (int r = 0; r < R; ++r)
        {
            // r行目を裏返すとき
            if (bit & (1 << r))
            {
                rep(c ,0, C){
                    if (senbei[r][c]==1)
                        senbei[r][c] = 0;
                    else
                        senbei[r][c] = 1;
                }
            }
        }
        // 一列ずつ"1"(裏)の枚数を見ていく
        rep(c, 0, C){
            int rev_col = 0;
            rep(r, 0, R)
            {
                rev_col += senbei[r][c];
            }
            rev += max(rev_col, R-rev_col);
        }
        res = max(res, rev);
    }
    cout << res << endl;
    return 0;
}