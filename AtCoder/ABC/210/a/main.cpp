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
    int N, A, X, Y;
    cin >> N >> A >> X >> Y;

    ll res;
    if (N <= A)
    {
        res = X * N;
    }
    else
    {
        res = X * A + Y*(N-A);
    }

    cout << res << endl;
    return 0;
}