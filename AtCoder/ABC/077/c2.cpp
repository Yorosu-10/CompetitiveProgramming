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
    int N;
    cin >> N;

    vector<int> A(N), B(N), C(N);

    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];
    rep(i, N) cin >> C[i];

    sort(A.begin(), A.end());
    sort(C.begin(), C.end());

    ll res = 0;
    // Bを全探索
    rep(i, N){
        // Bの要素より小さいAの要素の個数
        ll A_cnt = lower_bound(A.begin(), A.end(), B[i]) - A.begin();
        // Bの要素より大きいCの要素の個数
        ll C_cnt = C.end()-upper_bound(C.begin(), C.end(), B[i]);
        res += A_cnt * C_cnt;
    }

    cout << res << endl;

    return 0;
}