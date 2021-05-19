#include <bits/stdc++.h>
typedef long long ll;
typedef long long int lli;
typedef long double ld;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

// エラトステネスの篩
vector<bool> sieve(size_t max) // max=正の整数n
{
    vector<bool> IsPrime; // 数字が素数かどうか判定するフラグ
    if (max + 1 > IsPrime.size())
    {                                  // resizeで要素数が減らないように
        IsPrime.resize(max + 1, true); // IsPrimeに必要な要素数を確保
    }
    IsPrime[0] = false; // 0は素数ではない
    IsPrime[1] = false; // 1は素数ではない

    for (size_t i = 2; i * i <= max; ++i)         // 0からsqrt(max)まで調べる
        if (IsPrime[i])                           // iが素数ならば
            for (size_t j = 2; i * j <= max; ++j) // (max以下の)iの倍数は
                IsPrime[i * j] = false;           // 素数ではない

    return IsPrime;
}

int main()
{   
    // 10^5までの素数をリスト化
    // 数字が素数かどうか判定するフラグを作成
    vector<bool> IsPrime=sieve(100000);

    // その数以下の「2017に似た数」がいくつあるかリスト化
    vector<int> PrimeNum(100000+1, 0);
    PrimeNum[0] = 0;

    for (int i = 1; i < (int)PrimeNum.size(); ++i)
    {
        PrimeNum[i] = PrimeNum[i - 1];
        if (IsPrime[i] && IsPrime[(i + 1) / 2])
            PrimeNum[i] = PrimeNum[i] + 1;
    }

    int Q, l, r;
    cin >> Q;

    rep(i, Q){
        cin >> l >> r;
        cout << (PrimeNum[r]-PrimeNum[l-1]) << endl;
    }
    return 0;
}