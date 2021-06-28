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
    vector<ll> A;   // 1次元, n個の要素
    vector<ll> oddA;   // 1次元, n個の要素
    rep(i, 0, 200){
        int tmp_i = i;
        ll tmp = (tmp_i + 1) * (tmp_i + 2) * (tmp_i + 3) / 6;
        A.push_back(tmp);
        if(tmp%2==1){
            oddA.push_back(tmp);
        }
    }

    int size_A = A.size();
    int size_oddA = oddA.size();

    // DP
    vector<int> dp(1e6, INF); // 1次元, n個の要素
    vector<int> odd_dp(1e6, INF); // 1次元, n個の要素

    dp[0] = 0;
    odd_dp[0] = 0;

    rep(i, 1, 1e6)
    {
        rep(j, 0, size_A)
        {
            if(i>=A[j]){
                dp[i] = min(dp[i], dp[i - A[j]] + 1);
            }
        }
            
        rep(k, 0, size_oddA){
            if(i>=oddA[k]){
                odd_dp[i] = min(odd_dp[i], odd_dp[i - oddA[k]] + 1);
            }
        }
    }

    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        cout << dp[n] << " " << odd_dp[n] << endl;
    }
    return 0;
}