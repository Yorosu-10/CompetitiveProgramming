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
    ll W;
    cin >> N >> W;

    int S, T;
    ll P;

    vector<ll> a(200001,0);
    rep(i, 0, N)
    {
        cin >> S >> T >> P;
        a[S] += P;
        a[T] += -P;
    }

    vector<ll> sum_a(200001, 0);
    bool can = true;
    rep(i, 1, 200001)
    {
        sum_a[i] = sum_a[i - 1] + a[i - 1];
        if(sum_a[i] > W){
            can = false;
            break;
        }
    }

    if(can)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}