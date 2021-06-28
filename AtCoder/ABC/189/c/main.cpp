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
    cin >> N;
    vector<int> A(N); // 1次元, n個の要素
    rep(i, 0, N){
        cin >> A[i];
    }

    ll res = 0;
    
    rep(l, 0, N)
    {
        int m = INF;
        rep(r, l, N){
            m = min(m, A[r]);
            ll tmp = m * (r - l + 1);
            res = max(res, tmp);
        }
    }

    cout << res << endl;
    return 0;
}