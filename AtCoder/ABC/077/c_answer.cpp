#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const double PI = acos(-1);
using namespace std;

int N, A[101010], B[101010], C[101010];
//---------------------------------------------------------------------------------------------------

using namespace std;
int main()
{
    cin >> N;
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];
    rep(i, N) cin >> C[i];
    sort(A, A + N);
    sort(C, C + N);

    ll ans = 0;

    rep(b, N)
    {
        ll a = lower_bound(A, A + N, B[b]) - A;
        ll c = N - (upper_bound(C, C + N, B[b]) - C);
        ans += a * c;
    }
    cout << ans << endl;
}