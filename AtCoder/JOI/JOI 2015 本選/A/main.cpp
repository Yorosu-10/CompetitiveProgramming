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

    vector<int> imos(N, 0);

    int P1, P2;
    cin >> P1;
    P1--;
    rep(i, 1, M)
    {
        cin >> P2;
        P2--;
        int v = P1;
        int next_v = P2;
        if (next_v < v)
            swap(v, next_v);
        imos[v]++;
        imos[next_v]--;
        P1 = P2;
    }

    vector<ll> A(N-1), B(N-1), C(N-1);
    rep(i, 0, N-1){
        cin >> A[i] >> B[i] >> C[i];
    }

    // 鉄道0は[1]に対応、鉄道iは[i+1]に対応
    vector<int> Railway_num(N, 0);
    rep(i, 1, N){
        Railway_num[i] = imos[i - 1] + Railway_num[i - 1];
    }

    ll res = 0;
    // 鉄道1つ１つに切符かICか安いほうを選択
    rep(i, 1, N)
    {
        ll ticket = A[i - 1] * Railway_num[i];
        ll IC = C[i - 1] + B[i - 1] * Railway_num[i];
        res += min(ticket, IC);
    }

    cout << res << endl;

    return 0;
}