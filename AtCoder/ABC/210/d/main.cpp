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

int main()
{
    ll H, W, C;
    cin >> H >> W >> C;
    vector<vector<ll>> A(H, vector<ll>(W)); // 2次元, n行m列

    // 最低のAとってくる
    ll A_min = LINF;
    int h_min, w_min;

    rep(h, 0, H){
        rep(w, 0, W){
            cin >> A[h][w];
            if(A_min>A[h][w]){
                A_min = A[h][w];
                h_min = h;
                w_min = w;
            }
        }
    }

    // 最低のAから一番安い鉄道の引き方を全探索
    ll res = LINF;
    rep(h, 0, H){
        rep(w, 0, W)
        {
            // 最低のAの場合
            if(h==h_min && w==w_min)
                continue;

            ll money = A_min+A[h][w] +C*(abs(h-h_min)+abs(w-w_min));
            res = min(res, money);
        }
    }

    cout << res << endl;

    return 0;
}