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

ll A, B, X;

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

bool check(ll N){
    ll price = A * N + B * GetDigit(N);
    if(price<=X){
        return true;
    }else{
        return false;
    }
}

int main()
{
    cin >> A >> B >> X;

    // 二分探索
    // okに(明らかに)条件を満たす値を格納
    ll ok = 0;
    // ngに(明らかに)条件を満たさない値を格納
    ll ng = INF+1; // nは探索最大値
    while (abs(ng - ok) > 1)
    {
        ll mid = (ok + ng) / 2;
        if (check(mid))
            ok = mid;
        else
            ng = mid;
    }
    // ループを抜けると、(探索対象配列の値)<=(探索値)を満たす
    // 境界の(ギリギリの)探索対象配列indexがokに格納されている。

    cout << ok << endl;

    return 0;
}