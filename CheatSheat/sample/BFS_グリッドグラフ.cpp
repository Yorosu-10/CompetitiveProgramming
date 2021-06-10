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

// 四方向への移動ベクトル
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

// 入力
int H, W;
vector<string> field;

struct Coord{
    int x;
    int y;
};

int main()
{
    cin >> H >> W;

    // s と g のマスを特定する
    int sy, sx, gy, gx;
    for (int y = 0; y < H; ++y)
    {
        for (int x = 0; x < W; ++x)
        {
            if (field[y][x] == 's')
                sy = y, sx = x;
            if (field[y][x] == 'g')
                gy = y, gx = x;
        }
    }

    field.resize(H);
    for (int y = 0; y < H; ++y)
        cin >> field[y];

    // BFS のためのデータ構造
    queue<Coord> que;
    vector<vector<int>> dist(H, vector<int>(W, -1));

    // 初期設定
    dist[sy][sx] = 0;
    Coord start = {sx, sy};
    que.push(start); // 0 を橙色頂点にする

    // BFS 開始 (キューが空になるまで探索を行う)
    while (!que.empty())
    {
        Coord now = que.front(); // キューから先頭頂点を取り出す
        que.pop();

        // v から辿れる頂点をすべて調べる
        rep(i, 0, 4)
        {
            Coord next = {now.x + dx[i], now.y + dy[i]};
            if (dist[next.y][next.x] != -1)
                continue; // すでに発見済みの頂点は探索しない
            if (field[next.y][next.x] == '#')
                continue; // 進んだ先が壁の場合は探索しない
            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            dist[next.y][next.x] = dist[now.y][now.x] + 1;
            que.push(next);
        }
    }

    // スタート地点からゴール地点に移動する最小手数は？
    cout << dist[gy][gx] << endl;

    return 0;
}