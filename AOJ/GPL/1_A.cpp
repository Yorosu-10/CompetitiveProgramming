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
void dijkstra(const Graph &G, int s, vector<long long> &dis, vector<int> &prev)
{
    int N = G.size();
    dis.resize(N, INF);
    prev.resize(N, -1); // 初期化
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
                prev[e.to] = v; // 頂点 v を通って e.to にたどり着いた
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
    int V, E, s;
    cin >> V >> E >> s;

    // 重み付きグラフ受け取り
    Graph G(V);
    for (int i = 0; i < E; ++i)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        G[from].push_back(Edge(to, weight));
    }

    // ダイクストラ法の結果を受け取る配列群
    // 開始点sから各点への最短距離
    vector<long long> d;
    // 各点に最短距離で到達する直前にいた点
    vector<int> prev;

    // ダイクストラ法
    dijkstra(G, s, d, prev);

    // 最短距離の経路復元
    int t = V - 1; // 終了点
    vector<int> path = get_path(prev, t);

    // 出力
    for (int i = 0; i < V; ++i){
        if (d[i]<INF){
            cout << d[i] << endl;
        }else{
            cout << "INF" << endl;
        }
    }

    return 0;
}