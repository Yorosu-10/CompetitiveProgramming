// https : //algo-logic.info/bridge-lowlink/

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

struct UnionFind
{
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N)
    { //最初は全てが根であるとして初期化
        for (int i = 0; i < N; i++)
            par[i] = i;
    }

    int root(int x)
    { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x)
            return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y)
    {                     // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry)
            return;   //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(int x, int y)
    { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main()
{
    int N, M;
    cin >> N >> M;

    // 集合は{0, 1,..., N-1}と0はじまりである必要がある。
    UnionFind tree(N);

    vector<int> a(M), b(M);

    for (int i = 0; i < M; i++){
        cin >> a[i] >> b[i];
        --a[i];
        --b[i];
    }

    /*
    全ての辺 e1=(u1,v1) に対して以下を実行する
        e1 以外の全ての辺 e2=(u2,v2) について以下を実行する
            u2 と v2 を Union-Find Tree 上の同じ集合にまとめる (unite)
            u1 と v1 が同じ集合になければ、e1 を除いたグラフは非連結で、e1 は橋
    */

    int res = 0;
    // すべての辺を全探索
    for (int i = 0; i < M; i++)
    {
        // 集合は{0, 1,..., N-1}と0はじまりである必要がある。
        UnionFind tree(N);

        // ei={a[i], b[i]}以外を全探索
        for (int j = 0; j < M; j++){
            if(j!=i)
                tree.unite(a[j], b[j]); // xの木とyの木を併合する
        }

        // 集合が同じでなければ、その辺は橋
        if (!tree.same(a[i], b[i]))
            res++;
    }

    cout << res << endl;

    return 0;
}