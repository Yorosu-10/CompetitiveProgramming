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
    ll N, S, D;
    cin >> N >> S >> D;

    ll X, Y;
    bool can = false;

    rep(i, 0, N){
        cin >> X >> Y;
        if(X<S && Y>D){
            can = true;
        }
    }

    if(can){
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}