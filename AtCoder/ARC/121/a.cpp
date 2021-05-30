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
    ll N;
    cin >> N;

    vector<pair<int, int>> x(N);
    vector<pair<int, int>> y(N);

    rep(i, 0, N){
        x[i].second = i;
        y[i].second = i;
        cin >> x[i].first >> y[i].first;
    }

    // vectorで昇順ソート
    sort(x.begin(), x.end());
    // vectorで昇順ソート
    sort(y.begin(), y.end());

    // [0]->No.1_dx [1]->No.1_dy
    // [2]->No.2_dx [3]->No.2_dy
    vector<ll> dx_dy(4);

    ll no1_diff, no2_diff, tmp;

    // 0行目はNo.1 1行目はNo.2
    vector<vector<int>> index(2, vector<int>(2)); // 2次元, n行m列

    no1_diff = x[N - 1].first - x[0].first;
    index[0][0] = min(x[N - 1].second, x[0].second);
    index[0][1] = max(x[N - 1].second, x[0].second);

    tmp = y[N - 1].first - y[0].first;
    if(tmp>)

    // No .2_dxについて
    ll kouho1, kouho2;
    kouho1 = x[N - 2].first - x[0].first;
    kouho2 = x[N - 1].first - x[1].first;
    if(kouho1>kouho2)
        dx_dy[2] = kouho1;
    else
        dx_dy[2] = kouho2;

    // No .2_dxについて
    kouho1 = y[N - 2].first - y[0].first;
    kouho2 = y[N - 1].first - y[1].first;
    if (kouho1 > kouho2)
        dx_dy[3] = kouho1;
    else
        dx_dy[3] = kouho2;

    sort(dx_dy.rbegin(), dx_dy.rend());

    cout << dx_dy[1] << endl;

    return 0;
}