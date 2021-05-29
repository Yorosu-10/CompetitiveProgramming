#include <bits/stdc++.h>
typedef long long ll;
typedef long long int lli;
typedef long double ld;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using Graph = vector<vector<int>>;
using namespace std;

/*
#######################################################################
深さ優先探索
#######################################################################
*/

// https://qiita.com/drken/items/a803d4fc4a727e02f7ba

/*
#######################################################################
その１：グラフのsからtにたどり着けるか問題（有向グラフの場合）
#######################################################################
*/
vector<bool> seen; // 訪問済みか否かを管理する

void dfs(const Graph &G, int v)
{
    seen[v] = true; // v を訪問済にする

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v])
    {
        if (seen[next_v])
            continue;   // next_v が探索済だったらスルー
        dfs(G, next_v); // 再帰的に探索
    }
}

int main()
{
    // 頂点数と辺数、s と t
    int N, M, s, t;
    cin >> N >> M >> s >> t;

    // グラフ入力受取
    Graph G(N);
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        // 無向グラフの場合は以下を追加
        // G[b].push_back(a);
    }

    // 頂点 s をスタートとした探索
    seen.assign(N, false); // 全頂点を「未訪問」に初期化
    dfs(G, s);

    // t に辿り着けるかどうか
    if (seen[t])
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

/*
#######################################################################
その1-2：グラフのsからtにたどり着けるか問題（グリッドグラフの場合）
#######################################################################
*/

// https://qiita.com/drken/items/a803d4fc4a727e02f7ba
// このサイトを見ること。冗長なのでここには転記しない。

/*
#######################################################################
その1-2：グラフのsからtにたどり着けるか問題（グリッドグラフの場合）
#######################################################################
*/
int main()
{
    // 頂点数と辺数
    int N, M;
    cin >> N >> M;

    // グラフ入力受取
    Graph G(N);
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // 全頂点が訪問済みになるまで探索
    int count = 0;
    seen.assign(N, false);
    for (int v = 0; v < N; ++v)
    {
        if (seen[v])
            continue; // v が探索済みだったらスルー
        dfs(G, v);    // v が未探索なら v を始点とした DFS を行う
        ++count;
    }
    cout << count << endl;
}