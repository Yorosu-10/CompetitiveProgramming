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
    ll d;
    int n, m;
    

    while (cin >> d)
    {
        cin >> n >> m;
        vector<ll> vec_d(n, 0);
        vector<ll> vec_k(m);
        for (int i = 1; i < n; ++i)
            cin >> vec_d[i];
        sort(vec_d.begin(), vec_d.end());
        rep(i, m) cin >> vec_k[i];

        ll len=0;
        rep(i, m)
        {
            // k[i]以上の一番左の店舗インデックスを求める
            auto Iter = lower_bound(vec_d.begin(), vec_d.end(), vec_k[i]);
            if(Iter==vec_d.end()){
                // 最短距離の店は0かn-1のどちらか
                if (abs(d - vec_k[i]) <= abs(vec_d[n-1] - vec_k[i]))
                {
                    len += abs(d - vec_k[i]);
                }
                else
                {
                    len += abs(vec_d[n - 1] - vec_k[i]);
                }
                continue;
            }
            int Index = Iter-vec_d.begin();
            if(Index == 0){
                continue;
            }
            // 最短距離の店はIndex or Index-1
            if (abs(vec_d[Index] - vec_k[i]) <= abs(vec_d[Index-1] - vec_k[i])){
                len += abs(vec_d[Index] - vec_k[i]);
            }
            else
            {
                len += abs(vec_d[Index - 1] - vec_k[i]);
            }
        }
        cout << len << endl;
    }

    return 0;
}