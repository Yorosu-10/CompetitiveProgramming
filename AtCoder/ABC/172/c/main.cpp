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

bool check(int mid){

}

int main()
{
    int N, M;
    ll K;

    cin >> N >> M >> K;

    vector<ll> Atot(N+1,0), Btot(M+1,0);
    ll a, b;
    rep(i, 1, N + 1){
        cin >> a;
        Atot[i] = Atot[i - 1] + a;
    }
    rep(i, 1, M+1){
        cin >> b;
        Btot[i] = Btot[i - 1] + b;
    }

    // 尺取り法
    int ans = 0;
    int ok = M;
    rep(a, 0, N + 1)
    {
        while (0 <= ok && K < Atot[a] + Btot[ok])
            ok--;
        if (0 <= ok)
            ans = max(ans, a + ok);
    }

    cout << ans << endl;
    return 0;
}