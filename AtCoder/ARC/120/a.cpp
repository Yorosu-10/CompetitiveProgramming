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
    int n;
    cin >> n;

    // 累積和
    vector<ll> Sum_A(n, 0);
    // 累積max
    vector<ll> max_A(n, 0);

    ll a;
    cin >> a;

    Sum_A[0] = a;
    max_A[0] = a;

    for (int i = 1; i < n; ++i){
        cin >> a;
        Sum_A[i] = Sum_A[i - 1] + a;
        max_A[i] = max(max_A[i - 1], a);
    }

    ll sum = 0;

    rep(i, 0, n){
        sum += Sum_A[i];
        cout << ((i + 1) * max_A[i] + sum) << endl;
    }

    return 0;
}