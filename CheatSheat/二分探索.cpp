

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

/*
#######################################################################
二分探索
#######################################################################
*/

bool check(){
}

int main()
{
    int n; 

    // https://www.forcia.com/blog/001434.html

    /* 二分探索 */
    // 探索対象配列はSort済みであること！
    // 探索対象の値が条件を満たすならば、OK
    // 探索対象の値が条件を満たさないならば、NG

    // okに(明らかに)条件を満たす値を格納
    int ok = -1;
    // ngに(明らかに)条件を満たさない値を格納
    int ng = n; // nは探索最大値
    while (abs(ng - ok) > 1)
    {
        int mid = (ok + ng) / 2;
        if (check())
            ok = mid;
        else
            ng = mid;
    }
    // ループを抜けると、(探索対象配列の値)<=(探索値)を満たす
    // 境界の(ギリギリの)探索対象配列indexがokに格納されている。
    
    //#######################################################################

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
    auto Iter = lower_bound(v.begin(), v.end(), 4);
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

    // 最大の最小/最小の最大を求める問題は、二分探索が定石。
    // 最小値、最大値を決め打ちして、二分探索で探索する。
}