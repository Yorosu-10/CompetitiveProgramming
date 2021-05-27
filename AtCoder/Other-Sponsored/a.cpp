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
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    // A0~Aiまでの合計値を格納する配列
    vector<ll> SUM_A(N+1, 0);
    rep(i, N){
        rep(j, i+1){
            SUM_A[i+1] += A[j];
        }
    }

    
    // kの値をforループ回す
    for (int k = 1; k <= N; ++k)
    {
        ll sum_max = 0;

        rep(i, N-k+1){
            sum_max = max(sum_max, SUM_A[i+k]-SUM_A[i]);
        }

        cout << sum_max << endl;
    }
    return 0;
}