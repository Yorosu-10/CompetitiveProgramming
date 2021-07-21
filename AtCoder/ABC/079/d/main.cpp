/*
任意の2頂点の対に対して最短経路を求める方法
計算量：O(N^3)
*/

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

void warshall_floyd(vector<vector<long long int>> &d)
{
    int n = (int)d.size();              // nは頂点数
    for (int i = 0; i < n; i++)         // 経由する頂点
        for (int j = 0; j < n; j++)     // 開始頂点
            for (int k = 0; k < n; k++) // 終端
                d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
}

int main()
{
    // nは頂点数、mは辺数
    int n = 10;

    // グラフの距離を格納した2次元配列（隣接行列）
    // d[u][v]は辺e=(u,v)のコスト（辺が存在しない場合はLINF、ただしd[i][i]=0）
    vector<vector<ll>> d(n, vector<ll>(n, LINF));

    int H, W;
    cin >> H >> W;

    // DP初期条件：問題条件
    rep(i, 0, 10)
        rep(j, 0, 10)
            cin >> d[i][j];

    warshall_floyd(d);

    // 0~9の数字が壁に計何個書かれているか
    int a;
    vector<int> cnt(10, 0);
    rep(i, 0, H){
        rep(j, 0, W){
            cin >> a;
            if(a!=-1)
                cnt[a]++;
        }
    }

    ll res = 0;
    rep(i, 0, 10)
        res += cnt[i] * d[i][1];

    cout << res << endl;
    return 0;
}