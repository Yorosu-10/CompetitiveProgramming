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
    int n, m;
    cin >> n;

    // グラフの距離を格納した2次元配列（隣接行列）
    // d[u][v]は辺e=(u,v)のコスト（辺が存在しない場合はINF、ただしd[i][i]=0）
    vector<vector<ll>> d(n, vector<ll>(n, LINF));

    // DP初期条件：dp[i][i]=0
    for (int i = 0; i < n; i++)
        d[i][i] = 0;

    cin >> m;
    // DP初期条件：問題条件
    for (int i = 0; i < m; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        d[from-1][to-1] = cost;
        d[to-1][from-1] = cost;
    }

    warshall_floyd(d);

    auto min_val = INF;
    rep(i, 0, n)
    {
        if(*max_element(d[i].begin(), d[i].end())<min_val){
            min_val = *max_element(d[i].begin(), d[i].end());
        }
    }

    cout << min_val << endl;

    return 0;
}