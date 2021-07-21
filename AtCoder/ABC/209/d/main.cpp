/*
木の2部グラフ性

高橋王国はグラフ理論の用語でいう木構造をなしています。
道路の長さを1 として、街 1 との最短距離が偶数であるような街を赤、そうでない街を青で塗ることにします。
すると、木の二部グラフ性により、赤の街にいた人は次青の街へ、逆に青の街にいた人は次赤の街へ移動するということが分かります。
よって高橋君と青木君のスタート地点の色が異なっていれば、二人は必ず同じ街で出会うことはありません。
逆に、高橋君と青木君のスタート地点の色が同じであれば、二人は必ず道路で出会うことはありません。
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

int main()
{
    int N,Q;
    cin >> N >> Q;

    // 重み付きグラフ受け取り
    Graph G(N);
    for (int i = 0; i < N-1; ++i)
    {
        int from, to;
        cin >> from >> to;
        G[from-1].push_back(to-1);
        G[to - 1].push_back(from - 1);
    }

    int c, d;
    // BFS のためのデータ構造
    vector<int> dist(N, -1); // 全頂点を「未訪問」に初期化
    queue<int> que;

    // 初期条件 (頂点 c を初期ノードとする)
    dist[0] = 0;
    que.push(0); // c を橙色頂点にする

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

    // クエリ処理
    rep(q, 0, Q){
        cin >> c >> d;
        c--;
        d--;

        if (dist[c] % 2 == dist[d] % 2)
        {
            cout << "Town" << endl;
        }
        else
        {
            cout << "Road" << endl;
        }
    }
    

    return 0;
}