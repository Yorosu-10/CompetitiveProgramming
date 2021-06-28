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
    double X, Y, r;
    cin >> X >> Y >> r;

    X *= 10000;
    ll Xo = (ll)X;
    Y *= 10000;
    ll Yo = (ll)Y;
    r *= 10000;
    ll R = (ll)r;

    ll x_max = Xo + R;
    ll x_min = Xo - R;

    ll res = 0;

    for (int x = x_min; x <= x_max;){
        if(x%10000!=0)
            continue;
        double theta = acos((x - Xo)/R);
        ll y_max = R * sin(theta) + Yo;
        ll y_min = -1 * R * sin(theta) + Yo;
        // 整数y_min~y_maxの間に10000の約数がいくつあるか？
        res += (y_max/10000-(y_min-1)/10000);
        
        x += 10000;
    }

    cout << res << endl;
    
    return 0;
}