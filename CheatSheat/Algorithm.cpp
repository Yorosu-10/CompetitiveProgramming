#include <bits/stdc++.h>
typedef long long ll;
typedef long long int lli;
typedef long double ld;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
int N, k;

int main(){
/*
#######################################################################
全探索
#######################################################################
*/
    //バケット法
    // ABC200C

    // ビット全探索 
    // ABC45C, ABC128C, ABC147C, ABC79C, ABC197C
    for (int bit = 0; bit < (1 << N); ++bit)
    {
    }

    // 3次元ビット全探索
    // ABC31D 
    int len[10];
    for (int bit = 0; bit < pow(3, k); ++bit)
    {
        int tmp = bit;
        // 3進数への変換 // 2進数と違い自分で変換しなくてはならない
        for (int pos = 1; pos <= k; ++pos)
        {   
            len[pos] = tmp % 3;
            tmp /= 3;
        }
    }

    // 順列全探索
    // ABC145C, ABC150C
    vector<int> ord(N);
    for (int i = 0; i < N; i++)
        ord[i] = i;

    do
    {

    } while (next_permutation(ord.begin(), ord.end()));

    // 再帰関数を用いた全探索（DFS）
    // ABC165C, CPSCO2019 Session1 C

/*
#######################################################################
二分探索
#######################################################################
*/

// https://www.forcia.com/blog/001434.html

    /* 二分探索 */
    // 探索対象配列はSort済みであること！
    // (探索対象配列の値)<=(探索値)ならば、OK
    // (探索対象配列の値)> (探索値)ならば、NG
    int ok = -1;
    int ng = n;
    while (abs(ng - ok) > 1)
    {
        int mid = (ok + ng) / 2;
        if (S[mid] <= T[i])
            ok = mid;
        else
            ng = mid;
    }
    // ループを抜けると、(探索対象配列の値)<=(探索値)を満たす
    // 境界の(ギリギリの)探索対象配列indexがokに格納されている。

    // lower_boundとupper_boundの使い方
    // https: //qiita.com/ganariya/items/33f1326154b85db465c3
    /*
    lower_boundは、
    ソートされた配列内で"key値以上"の要素の内の一番左側のイテレータを返す
    upper_boundは、
    ソートされた配列内で"key値より大きい"要素の内の一番左側のイテレータを返す
    */
    vector<int> v = {1, 4, 4, 7, 7, 8, 8, 11, 13, 19};
    //イテレータを返す
    //見つからなかったらv.end()を返す。
    auto Iter = lower_bound(v.begin(),v.end(), 4);
    //インデックスを求める
    int Index = Iter - v.begin();

    /*
    =個数を求める====================================
    1. lower_boundのイテレータから先頭のイテレータを引くと、
    あるkeyより小さい要素の個数を求めることができる。
    2. 末尾のイテレータからlower_boundのイテレータを引くと、
    あるkey以上の要素の個数を求めることができる。
    3. upper_boundのイテレータから先頭のイテレータを引くと、
    あるkey以下の要素の個数を求めることができる。
    4. 末尾のイテレータからupper_boundのイテレータを引くと、
    あるkeyより大きい要素の個数を求めることができる。
    ===============================================
    */


/*
#######################################################################
高速なべき乗計算
#######################################################################
*/
    // aのn乗(a^n) mod を計算する  // https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a#4-%E7%B4%AF%E4%B9%97-an
    long long modpow(long long a, long long n, long long mod)
    {
        long long res = 1;
        while (n > 0)
        {
            if (n & 1)
                res = res * a % mod;
            a = a * a % mod;
            n >>= 1;
        }
        return res;
    }

    // aのmod mでの逆元を求める
    // mod mでのaの逆元が存在する条件は、mとaとが互いに素であること
    long long modinv(long long a, long long m)
    {
        long long b = m, u = 1, v = 0;
        while (b)
        {
            long long t = a / b;
            a -= t * b;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        u %= m;
        if (u < 0)
            u += m;
        return u;
    }

    // nCr modの計算
    // ABC034C

/*
#######################################################################
高速な素数判定法
#######################################################################
*/

    // 正の整数nを素因数分解（NTL_1_A）
    // 素因数格納配列に格納して返す
    vector<ll> PrimeFactorize(int n)
    {
        // 素因数格納配列
        vector<ll> PF;
        ll tmp_n = n;
        for (int i = 2; i * i <= n;) // i<=sqrt(n)まで探索
        {
            if (tmp_n % i == 0)
            {
                tmp_n = tmp_n / i;
                PF.push_back(i);
                if (tmp_n == 1)
                    break;
            }
            else
            {
                ++i;
            }
        }
        // 割っていった結果が1以外ならば最終要素として格納
        if (tmp_n != 1)
            PF.push_back(tmp_n);

        return PF;
    }


    // n以下の整数の素数をリスト化
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

/*
#######################################################################
累積和
#######################################################################
*/

    // 累積和 // [0]は0を代入
    vector<ll> Sum_A(n, 0);
    for (int i = 1; i <= n; ++i)
        Sum_A[i] = Sum_A[i - 1] + L[i - 1];

    // 二次元累積和
    // https://qiita.com/drken/items/56a6b68edef8fc605821
    vector<vector<int>> s(H + 1, vector<int>(W + 1, 0));
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            s[i + 1][j + 1] = s[i][j + 1] + s[i + 1][j] - s[i][j] + a[i][j];
