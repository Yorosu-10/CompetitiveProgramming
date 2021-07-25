// https://qiita.com/DaikiSuyama/items/ab8d7812e549c2f2e9cf
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

    ll res = 0;
    for (int n = 1; n <= N; n++)
    {
        ll c = N/n;
        res += (n + c * n) * c / 2;
    }
    cout << res << endl;
    return 0;
}