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
    ll A, B, C, D;
    cin >> A >> B >> C >> D;

    ll tmp = (C * D - B);

    if(tmp<=0){
        cout << "-1" << endl;
        return 0;
    }

    ll res = (A + (tmp - 1)) /tmp;

    cout << res << endl;

    return 0;
}