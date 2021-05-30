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
    ll N, K;
    cin >> N >>K;
    // 友達
    vector<pair<ll, ll>> f(N);

    rep(i, 0, N){
        cin >> f[i].first >> f[i].second;
    }

    //昇順ソート
    sort(f.begin(), f.end());
    
    // 所持金
    ll money = K;
    ll tmp;
    // 現在地
    ll v = 0;

    rep(i, 0, N){
        tmp = money;
        money = money - (f[i].first - v);
        if(money<0){
            money = tmp;
            break;
        }
            
        money = money + f[i].second;
        v = f[i].first;
    }

    ll res = money + v;

    cout << res << endl;

    return 0;
}