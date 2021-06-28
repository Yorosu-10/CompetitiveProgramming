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
    int N;
    ll C;
    cin >> N >> C;

    vector<pair<ll, ll>> event;

    ll a, b, c;
    rep(i, 0, N)
    {
        cin >> a >> b >> c;
        event.push_back({a-1, c});
        event.push_back({b, -c});
    }
    //sort
    sort(event.begin(), event.end());

    ll res = 0;

    ll day = event[0].first;
    ll ev_day;
    ll money = 0;
    rep(i, 0, 2*N-1)
    {
        money += event[i].second;
        if(event[i].first != event[i+1].first){
            ev_day = event[i+1].first;
            if(money<C)
                res += money*(ev_day-day);
            else
                res += C * (ev_day - day);
            day = ev_day;
        }
    }
    cout << res << endl;
    return 0;
}