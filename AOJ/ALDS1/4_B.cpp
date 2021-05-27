#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const double PI = acos(-1);
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> S(n);
    rep(i, n) cin >> S[i];

    int q;
    cin >> q;
    vector<int> T(q);
    rep(i, q) cin >> T[i];

    int res = 0;
    rep(i, q)
    {
        /* 二分探索 */
        // (Listの値)<=(探索値)ならば、OK
        // (Listの値)> (探索値)ならば、NG
        int ok = -1;
        int ng = n;
        while (abs(ng - ok) > 1)
        {
            int mid = (ok + ng) / 2;
            if (S[mid] <= T[i])
                ok = mid;
            else
                ng = mid;
        }
        // （見つかった場合）ループを抜けると探索値のindexがokに格納されている。
        // （見つからなかった場合）探索値のindexがokに格納されていない。
        if(S[ok]==T[i])
            res++;
    }

    cout << res << endl;

    return 0;
}