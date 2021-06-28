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
    int N;
    cin >> N;

    int t;
    vector<ll> l(N), r(N); // 1次元, n個の要素

    // すべて閉区間に直す
    rep(i, 0, N){
        cin >> t >> l[i] >> r[i];
        l[i] *= 10;
        r[i] *= 10;
        if (t == 2)
        {
            r[i]-=1;
        }
        else if (t == 3)
        {
            l[i]+=1;
        }
        else if (t == 4)
        {
            l[i]+=1;
            r[i]-=1;
        }
    }

    // 全探索
    ll res = 0;
    rep(i, 0, N - 1)
    {
        rep(j, i+1,N){
            if(r[j]<l[i] || r[i]<l[j]){
                continue;
            }else{
                res++;
            }
        }
    }

    cout << res << endl;

    return 0;

}