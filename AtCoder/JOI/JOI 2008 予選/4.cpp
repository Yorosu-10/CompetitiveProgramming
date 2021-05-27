#include <bits/stdc++.h>
typedef long long ll;
typedef long long int lli;
typedef long double ld;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main()
{
    int m, n;
    cin >> m;

    // 星座位置
    vector<vector<ll>> constellation(m, vector<ll>(2));
    constellation[0][0] = 0;
    constellation[0][1] = 0;
    ll dx, dy, tmp_x, tmp_y;
    // 1つめの星の位置を(0, 0)となるようにすべての星を平行移動させる
    cin >> dx >> dy;
    for (int i = 1; i < m;++i)
    {
        cin >> tmp_x >> tmp_y;
        constellation[i][0] = tmp_x - dx;
        constellation[i][1] = tmp_y - dy;
    }

    cin >> n;
    // 写真の星の座標
    vector<ll> starpos_x(n);
    vector<ll> starpos_y(n);
    // 座標表面上に写真の星が存在しているかフラグ
    // これはアクセスに時間がかかる
    // vector<vector<bool>> StarPosFlag(1000001, vector<bool>(1000001, false));
    rep(i, n){
        cin >> tmp_x >> tmp_y;
        starpos_x[i] = tmp_x;
        starpos_y[i] = tmp_y;
        //StarPosFlag[tmp_x][tmp_y] = true;
    }

    // 写真の星たちを星座[0]に当てはめて１つ１つを全探索
    rep(i, n){
        bool can = true;
        for (int j = 1; j < m; ++j)
        {
            tmp_x = starpos_x[i] + constellation[j][0];
            tmp_y = starpos_y[i] + constellation[j][1];
            if (tmp_x < 0 || 1000000 < tmp_x || tmp_y < 0 || 1000000 < tmp_y)
            {
                can = false;
                break;
            }
            if (find(starpos_x.begin(), starpos_x.end(), tmp_x) == starpos_x.end() || find(starpos_y.begin(), starpos_y.end(), tmp_y) == starpos_y.end())
            {
                can = false;
                break;
            }
        }
        if(can){
            cout << (starpos_x[i] - dx) << " " << (starpos_y[i] - dy) << endl;
            break;
        }
    }

    return 0;
}