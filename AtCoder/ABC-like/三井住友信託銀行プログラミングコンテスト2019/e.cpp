#include <bits/stdc++.h>
typedef long long ll;
typedef long long int lli;
typedef long double ld;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int N, A[101010];
int cnt[101010];
//---------------------------------------------------------------------------------------------------
ll solve()
{
    ll ans = 1;
    rep(i, N) A[i]++;
    cnt[0] = 3;
    rep(i, N)
    {
        if (0 < cnt[A[i] - 1])
        {
            ans *= cnt[A[i] - 1];
            cnt[A[i] - 1]--;
            cnt[A[i]]++;
        }
        else
            return 0;
    }
    return ans;
}
//---------------------------------------------------------------------------------------------------
int main()
{
    cin >> N;
    rep(i, N) cin >> A[i];
    cout << solve() << endl;
}

