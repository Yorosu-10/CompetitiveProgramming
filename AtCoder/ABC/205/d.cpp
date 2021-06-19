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
    int N, Q;
    cin >> N >>Q;

    vector<ll> A(N);
    rep(i, 0, N){
        cin >> A[i];
    }

    // 累積
    vector<ll> ruiseki(N);
    // 初期条件
    ruiseki[0] = A[0] - 1;

    for (int i = 0; i < N-1; ++i)
        ruiseki[i+1] = ruiseki[i] + (A[i+1]-A[i]-1);

    ll K;
    ll res;
    rep(i, 0, Q)
    {
        cin >>K;

        //イテレータを返す
        //見つからなかったらv.end()を返す。
        auto Iter = lower_bound(ruiseki.begin(), ruiseki.end(), K);
        //インデックスを求める
        int Index = Iter - ruiseki.begin();
        if(Index == N){
            res = A[N - 1] + (K - ruiseki[N-1]);
        }
        else
        {
            if(K==ruiseki[Index]){
                res = A[Index] - 1;
            }else{
                res = A[Index] - 1 - (ruiseki[Index] - K);
            }
        }
        cout << res << endl;
    }

    return 0;
}