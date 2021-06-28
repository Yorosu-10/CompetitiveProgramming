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
    int N, M;
    cin >> N >> M;

    if(M==0){
        cout << "1" << endl;
        return 0;
    }

    vector<ll> A(M);
    rep(i, 0, M){
        cin >> A[i];
    }

    // vectorで昇順ソート
    sort(A.begin(), A.end());

    ll before = 0;
    ll k = LINF;
    rep(i, 0, M)
    {
        if (A[i] - before - 1>0)
        {
            k = min(k, A[i] - before - 1);
        }
        before = A[i];
    }
    if(N-before>0){
        k = min(k, N - before);
    }

    if(k==LINF){
        cout << "0" << endl;
        return 0;
    }

    ll res = 0;
    before = 0;
    rep(i, 0, M)
    {
        if (A[i] - before - 1 > 0)
        {
            res += (A[i] - before - 1 +(k - 1)) / k;
        }
        before = A[i];
    }
    if (N - before > 0)
    {
        res += (N - before + (k - 1)) /k;
    }

    cout << res << endl;

    return 0;
}