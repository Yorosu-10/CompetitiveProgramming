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

    vector<ll> A(N); // 1次元, n個の要素

    rep(i, 0, N)
    {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    vector<int> count;
    int cnt = 1;

    rep(i, 1, N){
        if(A[i]==A[i-1]){
            cnt++;
            if(i==N-1){
                count.push_back(cnt);
            }
        }else{
            count.push_back(cnt);
            cnt = 1;
            if (i == N - 1)
            {
                count.push_back(1);
            }
        }
    }

    ll res = N*(N-1)/2;

    for (int i = 0; i < (int)count.size(); ++i)
    {
        if(count[i]>1)
            res -= count[i] * (count[i] - 1) / 2;
    }
    cout << res << endl;

    return 0;
}