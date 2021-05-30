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
set<ll> Set;

// 現在のx座標, y座標を入力
void dfs(const vector<vector<ll>> &G, ll x, ll y)
{
    

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v])
    {
        if (seen[next_v])
            continue;   // next_v が探索済だったらスルー
        dfs(G, next_v); // 再帰的に探索
    }
}

int main()
{
    // 頂点数と辺数、s と t
    int N, M
    cin >> N >> M;

    // グラフ入力受取
    vector<vector<ll>> G(N);

    // 出現x座標
    set<ll> x_set;

    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        x_set.insert(a);
        G[a].push_back(b);
        // 無向グラフの場合は以下を追加
        // G[b].push_back(a);
    }

    vector<ll> vec_x;

    for (auto xx : x_set)
    {
        vec_x.push_back(xx);
    }

    dfs(G, 0, N);

    // t に辿り着けるかどうか
    if (seen[t])
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}