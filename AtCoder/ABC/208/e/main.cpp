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

// 整数の桁数を取得
unsigned GetDigit(long long int num)
{
    unsigned digit = 0;
    while (num != 0)
    {
        num /= 10;
        digit++;
    }
    return digit;
}

int main()
{
    ll N ,K;
    cin >> N >> K;

    int dN = GetDigit(N);
    dN--;

    // dp[digit][m]
    // 2以上の数しか使わずに、その桁(digit)でその積(m)になる数の個数
    // digitは0はじまり
    vector<vector<int>> dp(18, vector<int>(1e5)); // 2次元, n行m列

    // 初期条件
    // dp[0][2~9] = 

    return 0;
}