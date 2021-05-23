#include <bits/stdc++.h>
typedef long long ll;
typedef long long int lli;
typedef long double ld;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main()
{
    int N;
    cin >> N;

    int A, C;
    vector<int> A_val_cnt(N,0), B(N), B_index_cnt(N, 0);

    rep(i, N){
        cin >> A;
        A_val_cnt[A-1]++;
    }
    rep(i, N){
        cin >> B[i];
        B[i]--;
    }
    rep(i, N){
        cin >> C;
        B_index_cnt[C - 1]++;
    }

    ll res = 0;
    // B[i]を前からみていく。
    rep(i,N){
        res += A_val_cnt[B[i]] * B_index_cnt[i];
    }

    cout << res << endl;

    return 0;
}