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

int V, E;
//  最小問題なので存在しない辺の重みはすべてINFで
vector<vector<int>> G(20, vector<int>(20, INF)); // 2次元, n行m列, 値'd'で初期化

int main()
{
    cin >> V >> E;
    // 初期化
    for (int i = 0; i < E; ++i)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        G[from][to]=weight;
    }

    // DP
    // 頂点集合セットSをすべて探索した時、頂点0からスタートして最後vにいるときの最短経路の距離
    vector<vector<int>> dp(1<<20, vector<int>(20, INF)); 
    // DP初期化
    dp[0][0] = 0;

    // dp[S∪v][v]=min_u∈S(dp[S][u]+cost(u,v))
    for (int S = 0; S < (1 << V); ++S){
        // 行き先の頂点
        rep(v, 0, V){
            // 現時点の頂点
            rep(u, 0, V){
                // uが含まれない場合をのぞく
                if(S!=0 && !(S&(1<<u))){
                    continue;
                }
                // 探索済みにvが含まれていない場合のみ
                if((S&(1<<v))==0){
                    if(v!=u)
                        dp[S | (1 << v)][v] = min(dp[S | (1 << v)][v], dp[S][u]+G[u][v]);
                }
            }
        }
    }

    if (dp[(1 << V) - 1][0] != INF)
    {
        cout << dp[(1 << V) - 1][0] << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}   