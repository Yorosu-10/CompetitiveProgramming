// https://atcoder.jp/contests/atc001/tasks/unionfind_a
// https://algo-logic.info/union-find-tree/

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

/* UnionFind：素集合系管理の構造体(union by size)
    isSame(x, y): x と y が同じ集合にいるか。 計算量はならし O(α(n))
    unite(x, y): x と y を同じ集合にする。計算量はならし O(α(n))
    treeSize(x): x を含む集合の要素数。
*/
struct UnionFind
{
    vector<int> size, parents;
    UnionFind() {}
    UnionFind(int n)
    { // make n trees.
        size.resize(n, 0);
        parents.resize(n, 0);
        for (int i = 0; i < n; i++)
        {
            makeTree(i);
        }
    }
    void makeTree(int x)
    {
        parents[x] = x; // the parent of x is x
        size[x] = 1;
    }
    bool isSame(int x, int y) { return findRoot(x) == findRoot(y); }
    bool unite(int x, int y)
    {
        x = findRoot(x);
        y = findRoot(y);
        if (x == y)
            return false;
        if (size[x] > size[y])
        {
            parents[y] = x;
            size[x] += size[y];
        }
        else
        {
            parents[x] = y;
            size[y] += size[x];
        }
        return true;
    }
    int findRoot(int x)
    {
        if (x != parents[x])
            parents[x] = findRoot(parents[x]);
        return parents[x];
    }
    int treeSize(int x) { return size[findRoot(x)]; }
};

int main()
{
    int N, Q;
    cin >> N >> Q;

    // 集合は{0, 1,..., N-1}と0はじまりである必要がある。
    UnionFind tree(N);

    for (int i = 0; i < Q; i++)
    {
        int x, y;
        cin >> x >> y;

        tree.unite(x-1, y-1); // xの木とyの木を併合する        
    }

    int res = 0;
    rep(i, 0, N){
        res = max(res, tree.treeSize(i));
    }

    cout << res << endl;

    return 0;
}