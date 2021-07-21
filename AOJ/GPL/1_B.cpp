/*
重みつきグラフの単一始点最短経路問題に対して、
おもに負のコストの辺があるときに使われる。
最悪計算量は O(VE) で、負閉路の検出にも使える。
*/

// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B&lang=ja

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
    long long from;
    long long to;
    long long cost;
};
using Edges = vector<Edge>;

/* bellman_ford(Es,V,s,dis)
    入力: 全ての辺Es, 頂点数V, 開始点 s, 最短経路を記録するdis
    出力: 負の閉路が存在するなら ture
    計算量：O(|E||V|)
    副作用：dis が書き換えられる
*/
bool bellman_ford(const Edges &Es, int V, int s, vector<long long> &dis)
{
    dis.resize(V, INF);
    dis[s] = 0;
    int cnt = 0;
    while (cnt < V)
    {
        bool end = true;
        for (auto e : Es)
        {
            if (dis[e.from] != INF && dis[e.from] + e.cost < dis[e.to])
            {
                dis[e.to] = dis[e.from] + e.cost;
                end = false;
            }
        }
        if (end)
            break;
        cnt++;
    }
    return (cnt == V);
}

int main()
{
    int V, E, s;
    cin >> V >> E >> s;

    // 重み付きグラフ受け取り
    Edges Es(E);
    for (int i = 0; i < E; ++i)
        cin >> Es[i].from >> Es[i].to >> Es[i].cost;

    // ベルマンフォード法の結果を受け取る配列群
    // 開始点sから各点への最短距離
    vector<long long> d;

    // ベルマンフォード法
    bool negative = bellman_ford(Es, V, s, d);

    // 出力
    if(negative){
        cout << "NEGATIVE CYCLE" << endl;
    }else{
        for (int i = 0; i < V; ++i){
            if (d[i] < INF){
                cout << d[i] << endl;
            }else{
                cout << "INF" << endl;
            }
        }
    }
    
    return 0;
}