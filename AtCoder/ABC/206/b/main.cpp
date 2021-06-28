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
    ld N;
    cin >> N;

    ld res_tmp = ((-1.0 + sqrt(1 + 8 * N)) / 2.0);

    ll res;

    if(res_tmp==(ll)res_tmp){
        res = (ll)res_tmp;
    }
    else
    {
        res = (ll)(res_tmp + 1);
    }
    cout << res << endl;
    return 0;
}