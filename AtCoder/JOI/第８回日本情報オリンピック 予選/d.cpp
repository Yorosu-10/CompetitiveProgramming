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

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

// vector<vector<bool>> ice; // 2次元, 要素数指定なし

int n, m;

int res = 0;

void dfs(vector<vector<bool>> ice, int x, int y, int depth)
{
    depth++;
    res = max(res, depth);
    ice[y][x] = 0;
    int nx, ny;

    rep(i, 0, 4){
        nx = x + dx[i];
        ny = y + dy[i];
        if(nx<0 || ny<0 || nx>= n || ny>=m){
            continue;
        }
        if(!ice[ny][nx]){
            continue;
        }
        dfs(ice, nx, ny, depth);
    }
}

int main()
{
    cin >> n >> m;

    vector<vector<bool>> ice;

    ice.assign(m, vector<bool>(n, 0));

    bool exist;

    rep(j, 0, m){
        rep(i, 0, n){
            cin >> exist;
            ice[j][i] = exist;
        }
    }

    // vector<vector<bool>> shoki_ice=ice;

    rep(sx, 0, n)
    {
        rep(sy, 0, m){
            if (ice[sy][sx])
                dfs(ice, sx, sy, 0);
        }
    }

    cout << res << endl;

    return 0;
}