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

/*
#######################################################################
幅優先探索
#######################################################################
*/

/*
探索の始点となる頂点から、各頂点への最短経路を求めることのできるアルゴリズム
(dist[v] の値が、始点から v への最短経路の長さを表しています)
*/

/*
#######################################################################
その１：グラフのsからtに何秒でたどり着けるか問題
#######################################################################
*/

int main()
{
    // 頂点数と辺数
    int N, M;
    cin >> N >> M;

    // グラフ入力受取 (ここでは無向グラフを想定)
    Graph G(N);
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // BFS のためのデータ構造
    vector<int> dist(N, -1); // 全頂点を「未訪問」に初期化
    queue<int> que;

    // 初期条件 (頂点 0 を初期ノードとする)
    dist[0] = 0;
    que.push(0); // 0 を橙色頂点にする

    // BFS 開始 (キューが空になるまで探索を行う)
    while (!que.empty())
    {
        int v = que.front(); // キューから先頭頂点を取り出す
        que.pop();

        // v から辿れる頂点をすべて調べる
        for (int nv : G[v])
        {
            if (dist[nv] != -1)
                continue; // すでに発見済みの頂点は探索しない

            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }

    // 結果出力 (各頂点の頂点 0 からの距離を見る)
    for (int v = 0; v < N; ++v)
        cout << v << ": " << dist[v] << endl;

    return 0;
}

/*
#######################################################################
その２：グリッドグラフのsからtに何秒でたどり着けるか問題（二次元）
#######################################################################
*/

// AtCoder Beginner Contest 007 C - 幅優先探索
// https://atcoder.jp/contests/abc007/tasks/abc007_3

// sample/BFS_グリッドグラフ.cpp

/*
########
#s#g...#
#.###..#
#......#
########
*/