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

vector<vector<int>> seen; // 訪問済みか否かを管理する 
// 列[0]に発見時間、列[1]に捜索完了時間を記録する

// 時刻
int t;

void dfs_1(const Graph &G, int v)
{
    t += 1;

    // 発見時間を記録
    if(seen[v][0]==0) seen[v][0] = t;

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v])
    {
        if (seen[next_v][0]!=0)
            continue;     // next_v が探索済だったらスルー
        dfs_1(G, next_v); // 再帰的に探索
    }
    t += 1;
    // 捜索完了時刻を記録
    seen[v][1] = t;


}

int main()
{
    // 頂点数
    int N;
    cin >> N;

    int u, k, v;

    // グラフ入力受取
    Graph G(N);
    rep(i, 0, N){
        cin >> u;
        int uu = u - 1;
        cin >> k;
        rep(i, 0, k){
            cin >> v;
            G[uu].push_back(v-1);
        }
    }

    seen.assign(N, vector<int>(2, 0)); // 全頂点を0に初期化

    t = 0; // 時刻情報を初期化

    // 全頂点をスタートにして探索
    for (int s = 0; s < N; ++s)
    {
        if (seen[s][0]!=0) continue; // v が探索済みだったらスルー
        dfs_1(G, s);
    }

    rep(u, 0, N){
        int tmp = u + 1;
        cout << tmp << " " << seen[u][0] << " " << seen[u][1] << endl;
    }
}