#include <bits/stdc++.h>
typedef long long ll;
typedef long long int lli;
typedef long double ld;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

#define rep(rep_cnt, n) for(int rep_cnt = 0; rep_cnt < (int)(n); rep_cnt++)
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int> > A(N, vector<int>(M));

    rep(i, N){
        rep(j, M)
        {
            cin >> A[i][j];
        }
    }

    lli res = 0;
    // M曲の組み合わせを全探索
    // 1曲目
    for (int i = 0; i < M;++i){
        // 2曲目
        for (int j = i + 1; j < M; ++j)
        {
            lli sum = 0;
            // N人の点数を合計。
            for (int n = 0; n < N;++n){
                sum += max(A[n][i], A[n][j]);
            }
            if(res<sum)
                res = sum;
        }
    }
    cout << res << endl;
}