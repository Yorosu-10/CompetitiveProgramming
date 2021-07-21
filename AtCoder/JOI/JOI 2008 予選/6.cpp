/*
負の辺を含まない重み付きグラフの単一始点最短経路問題で使われる
N頂点M辺のグラフにおける頂点1から各頂点への最短経路長を、O(MlogN) で計算
*/

// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=ja

#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
#define rep(i, b, e) for (int i = (int)(b); i < (int)(e); i++)
const double PI = acos(-1);
using namespace std;

struct Edge
{
    long long to;
    long long cost;
    Edge(long long t, long long c) : to(t), cost(c) {}
};
using Graph = vector<vector<Edge>>;
using P = pair<long, int>;

/* dijkstra(G,s,dis,prev)
    入力：グラフ G, 開始点 s, 距離を格納する dis, 最短経路の前の点を記録するprev
    計算量：O(|E|log|V|)
    副作用：dis, prevが書き換えられる
*/
void dijkstra(const Graph &G, int s, vector<long long> &dis)
{
    int N = G.size();
    dis.resize(N, INF);
    priority_queue<P, vector<P>, greater<P>> pq;
    dis[s] = 0;
    pq.emplace(dis[s], s);
    while (!pq.empty())
    {
        P p = pq.top();
        pq.pop();
        int v = p.second;
        if (dis[v] < p.first)
        {
            continue;
        }
        for (auto &e : G[v])
        {
            if (dis[e.to] > dis[v] + e.cost)
            {
                dis[e.to] = dis[v] + e.cost;
                pq.emplace(dis[e.to], e.to);
            }
        }
    }
}

/* get_path(prev, t)
    入力：dijkstra で得た prev, ゴール t
    出力： t への最短路のパス（最短距離の経路復元）
*/
vector<int> get_path(const vector<int> &prev, int t)
{
    vector<int> path;
    for (int cur = t; cur != -1; cur = prev[cur])
    {
        path.push_back(cur);
    }
    reverse(path.begin(), path.end()); // 逆順なのでひっくり返す
    return path;
}

int main()
{
    int V;
    int k;
    cin >> V >> k;

    // 重み付きグラフ
    Graph G(V);

    for (int i = 0; i < k; ++i)
    {
        int q;
        cin >> q;
        if(q==1){
            int from, to, weight;
            cin >> from >> to >> weight;
            G[from-1].push_back(Edge(to-1, weight));
            G[to-1].push_back(Edge(from-1, weight));
        }else{
            int s, t;
            cin >> s >> t;
            // 開始点sから各点への最短距離
            vector<long long> d;
            // ダイクストラ法
            dijkstra(G, s-1, d);
            // 出力
            if (d[t-1] < INF)
                cout << d[t-1] << endl;
            else
                cout << "-1" << endl;
        }
    }

    return 0;
}