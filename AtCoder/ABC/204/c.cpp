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

vector<bool> seen; // 訪問済みか否かを管理する

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
        G[a-1].push_back(b-1);
    }

    // BFS のためのデータ構造
    vector<int> dist(N); // 全頂点を「未訪問」に初期化
    queue<int> que;

    ll count = 0;

    rep(i, 0, N)
    {
        // 初期設定
        rep(n, 0, N)
        {
            dist[n] = -1;
        }

        while (!que.empty())
            que.pop();

        dist[i] = 0;
        que.push(i);

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

        rep(n, 0, N)
        {
            if(dist[n] != -1)
                count++;
        }
    }

    cout << count << endl;
    return 0;
}