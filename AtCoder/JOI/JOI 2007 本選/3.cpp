#include <bits/stdc++.h>
typedef long long ll;
typedef long long int lli;
typedef long double ld;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> P(n, vector<int>(2)); // 2次元, n行m列

    // (0, 0)~(5000, 5000)の各点に存在するかどうかflagを作成
    vector<vector<bool>> zahyo(5001, vector<bool>(5001, false));

    rep(i, n)
    {
        cin >> P[i][0] >> P[i][1];
        zahyo[P[i][0]][P[i][1]] = true;
    }

    // 面積MAX値
    lli max_S = 0;
    lli S;

    int Xc, Xd, Yc, Yd;

    // 2点の選び方を全探索
    // 1点目（点A）
    for (int a = 0; a < n;++a){
        // 2点目（点B）
        for (int b = a + 1; b < n;++b)
        {
            lli dx = P[b][0] - P[a][0];
            lli dy = P[b][1] - P[a][1];
            // 点C座標(候補１)
            Xc = P[b][0] - dy;
            Yc = P[b][1] + dx;
            // 点D座標(候補１)
            Xd = P[a][0] - dy;
            Yd = P[a][1] + dx;
            // 点Cと点Dは存在してる？
            if (0 <= Xc && Xc <= 5000 && 0 <= Xd && Xd <= 5000 && 0 <= Yc && Yc <= 5000 && 0 <= Yd && Yd <= 5000){
                if (zahyo[Xc][Yc] == 1 && zahyo[Xd][Yd] == 1)
                {
                    // 存在してるなら辺の長さを計算。
                    S = dx*dx+dy*dy;
                    max_S = max(max_S, S);
                }
            }
                
            // 点C座標(候補２)
            Xc = P[b][0] + dy;
            Yc = P[b][1] - dx;
            // 点D座標(候補２)
            Xd = P[a][0] + dy;
            Yd = P[a][1] - dx;
            // 点Cと点Dは存在してる？
            if (0<=Xc&&Xc<=5000&&0<=Xd&&Xd<=5000&&0<=Yc&&Yc<=5000&&0<=Yd&&Yd<=5000)
            {
                if (zahyo[Xc][Yc] == 1 && zahyo[Xd][Yd] == 1)
                {
                    // 存在してるなら辺の長さを計算。
                    S = dx*dx + dy*dy;
                    max_S = max(max_S, S);
                }
            }
        }
    }

    cout << max_S << endl;

    return 0;
}