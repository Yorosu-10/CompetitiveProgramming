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
    int N, K;
    cin >> N >> K;

    // 色、数
    map<ll, int> M;

    vector<ll> c(N);
    rep(i,0,N){
        cin >> c[i];
    }

    // 最初のK個について
    int sp = 0;
    rep(i, 0, K)
    {
        if(M[c[i]]==0)
            sp++;
        M[c[i]]++;
    }

    int res = sp;
    for (int i = 0; i < N - K; ++i)
    {
        if (M[c[i]]==1){
            sp--;
        }
        M[c[i]]--;
        if (M[c[i + K]]==0){
            sp++;
        }
        M[c[i + K]]++;
        res = max(sp, res);
    }

    cout << res << endl;

    return 0;
}