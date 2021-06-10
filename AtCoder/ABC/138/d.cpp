// AtCoder Beginner Contest 138 D - Ki のテストケースがコンテスト後に増えている件について (修正版)
// https://qiita.com/c-yan/items/887e2c2f410ecec60650

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

vector<ll> res, counter;

void dfs(const Graph &G, int v, ll cnt)
{
    cnt += counter[v];
    res[v] += cnt;
    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]){
        dfs(G, next_v, cnt); // 再帰的に探索
    }
        
    
}

int main()
{
    int N, Q;
    cin >> N >> Q;

    // グラフ入力受取
    Graph G(N);

    vector<bool> flag(N, 0);
    flag[0] = true;

    for (int i = 0; i < N-1; ++i)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        if(!flag[a] && flag[b])
            swap(a, b);

        G[a].push_back(b);

        flag[b] = 1;
        // 無向グラフの場合は以下を追加
        // G[b].push_back(a);
    }

    int p, x;
    counter.assign(N, 0);
    rep(i, 0, Q)
    {
        cin >> p >> x;
        counter[p - 1] += x;
    }

    // 初期化
    res.assign(N, 0);


    dfs(G, 0, 0);


    rep(i, 0, N)
        cout << res[i] << " ";

    cout << endl;

    return 0;
}