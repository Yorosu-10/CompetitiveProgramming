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

    int N;
    cin >> N;

    // [0]は巣とする
    vector<Coord> Cheese(N+1);

    field.resize(H);
    for (int y = 0; y < H; ++y)
        cin >> field[y];

    for (int y = 0; y < H; ++y)
    {
        for (int x = 0; x < W; ++x)
        {
            if (field[y][x] == 'S')
                Cheese[0].y = y, Cheese[0].x = x;
            rep(i, 1, N+1){
                if (field[y][x] == '0'+i)
                    Cheese[i].y = y, Cheese[i].x = x;
            } 
        }
    }

    // BFS のためのデータ構造
    queue<Coord> que;
    vector<vector<int>> dist(H, vector<int>(W)); // 2次元, n行m列, 値'd'で初期化

    // 時間
    int time = 0;

    rep(i, 0, N){
        // 初期設定
        rep(y, 0, H){
            rep(x, 0, W){
                dist[y][x] = -1;
            }
        }
        dist[Cheese[i].y][Cheese[i].x] = 0;

        Coord start = {Cheese[i].x, Cheese[i].y};
        Coord goal = {Cheese[i+1].x, Cheese[i+1].y};

        while (!que.empty())
            que.pop();
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
                if(next.x<0 || next.x>=W || next.y<0 || next.y>=H)
                    continue; // 領域外の場合は探索しない
                if (dist[next.y][next.x] != -1)
                    continue; // すでに発見済みの頂点は探索しない
                if (field[next.y][next.x] == 'X')
                    continue; // 進んだ先が壁の場合は探索しない
                // 新たな白色頂点 nv について距離情報を更新してキューに追加する
                dist[next.y][next.x] = dist[now.y][now.x] + 1;
                if (next.x == goal.x && next.y == goal.y)
                    break; // nextが目標のチーズならbreak
                que.push(next);
            }
        }

        time += dist[goal.y][goal.x];
    }

    cout << time << endl;

    return 0;
}