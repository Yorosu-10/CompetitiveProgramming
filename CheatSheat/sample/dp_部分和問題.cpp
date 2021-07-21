/*
N個の数 a1,a2,…,an が与えられたとき、
その中からいくつかを選んで和をちょうど K にできるか判定をする
*/

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
    // 入力
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    // 二次元配列
    vector<vector<bool>> dp(N + 1, vector<bool>(K + 1, false));
    // 初期化
    for (int i = 0; i <= N; i++)
    {
        dp[i][0] = true;
    }
    // 更新
    for (int i = 0; i < N; i++)
    {
        for (int k = 0; k <= K; k++)
        {
            if (k - a[i] >= 0)
                dp[i + 1][k] = dp[i + 1][k] | dp[i][k - a[i]];
            dp[i + 1][k] = dp[i + 1][k] | dp[i][k];
        }
    }
    if (dp[N][K])
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}