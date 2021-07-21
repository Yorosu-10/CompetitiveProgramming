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

struct Coord
{
    int x;
    int y;
};

int main()
{
    // 入力
    int H, W;

    while (cin >> W >> H &&(W!=0 && H!=0)){
        // 壁の有無を格納する配列
        vector<vector<bool>> wall_w(H, vector<bool>(W - 1));
        vector<vector<bool>> wall_h(H - 1, vector<bool>(W));

        bool wall;
        rep(i, 0, 2 * H - 1)
        {
            if (i % 2 == 0)
            {
                rep(j, 0, W - 1)
                {
                    cin >> wall;
                    wall_w[i / 2][j] = wall;
                }
            }
            else
            {
                rep(j, 0, W)
                {
                    cin >> wall;
                    wall_h[i / 2][j] = wall;
                }
            }
        }

        // BFS のためのデータ構造
        queue<Coord> que;
        vector<vector<int>> dist(H, vector<int>(W, -1));

        // 初期設定
        dist[0][0] = 1;
        Coord start = {0, 0};
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
                if (next.x < 0 || next.y < 0 || next.x > W - 1 || next.y > H - 1)
                    continue; // 進んだ先が範囲外の場合は探索しない
                if (dist[next.y][next.x] != -1)
                    continue; // すでに発見済みの頂点は探索しない

                // 右
                if (i == 0)
                {
                    if (wall_w[now.y][now.x])
                        continue; // 進んだ先が壁の場合は探索しない
                }
                // 下
                else if (i == 1)
                {
                    if (wall_h[now.y][now.x])
                        continue; // 進んだ先が壁の場合は探索しない
                    // 左
                }
                else if (i == 2)
                {
                    if (wall_w[now.y][now.x - 1])
                        continue; // 進んだ先が壁の場合は探索しない
                    // 上
                }
                else
                {
                    if (wall_h[now.y - 1][now.x])
                        continue; // 進んだ先が壁の場合は探索しない
                }

                // 新たな白色頂点 nv について距離情報を更新してキューに追加する
                dist[next.y][next.x] = dist[now.y][now.x] + 1;
                que.push(next);
            }
        }

        // スタート地点からゴール地点に移動する最小手数は？
        if (dist[H - 1][W - 1] == -1)
        {
            cout << "0" << endl;
        }
        else
        {
            cout << dist[H - 1][W - 1] << endl;
        }
    }

    return 0;
}