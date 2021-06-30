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
    ll x, y, a ,b;
    cin >> x >> y >> a >> b;
    ll exc = 0;
    while ((double)a * x <= 2e18 && a * x <= x + b && a * x < y)
    {
        x *= a;
        exc++;
    }

    exc += (ll)(y - x-1) /b;

    cout << exc << endl;

    return 0;
}