// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C&lang=ja

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
    int n, m;
    cin >> n;

    // グラフの距離を格納した2次元配列（隣接行列）
    // d[u][v]は辺e=(u,v)のコスト（辺が存在しない場合はLINF、ただしd[i][i]=0）
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
        d[from][to] = cost;
    }

    warshall_floyd(d);

    // 負の閉回路(d[i][i]<0)が存在するかどうか確認
    bool negative = false;
    for (int i = 0; i < n ;++i){
        if(d[i][i]<0)
            negative = true;
    }

    // 出力
    if(negative){
        cout << "NEGATIVE CYCLE" << endl;
    }
    else{
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n-1; ++j){
                if (d[i][j] > 1e15){
                    cout << "INF" << " ";
                }else{
                    cout << d[i][j] << " ";
                }
            }
            if (d[i][n-1] > 1e15){
                cout << "INF" << endl;
            }else{
                cout << d[i][n-1] << endl;
            }
        }
    }

    return 0;
}