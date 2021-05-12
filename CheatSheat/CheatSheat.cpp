// 競技プログラムその他で使うチートシート
// ここからコピペして時短しよう

/*
#######################################################################
テンプレート （最初にコピペしておく）
#######################################################################
*/

#include <iostream>
#include <string>      // string
#include <algorithm>   // min, max, swap
#include <iomanip>　   // setprecision()
#include <cmath>　　　 // pow, sqrt
#include <vector>      // vector
using namespace std;

int main(){

    
    return 0;
}

/*
#######################################################################
入出力
#######################################################################
*/

// 出力を小数第〇位まで出力。この後に普通にcoutすればOK。
cout << fixed << setprecision(8);

// 整数部あわせて〇桁出力。
cout << setprecision(16);

/*
#######################################################################
構造体
#######################################################################
*/
struct person
{
    long long int A;
    long long int B;
};

/*
#######################################################################
数学関数
#######################################################################
*/

// 絶対値
abs(X);
// XのY乗
pow(X, Y);
// Xの平方根
sqrt(X);
// 円周率
M_PI
// sin  C:度数法
sin(M_PI *C / 180);
// cos  C:度数法
cos(M_PI *C / 180);

/*
#######################################################################
配列
#######################################################################
*/

// vector // 宣言
vector<int> v();    // 1次元, 要素数指定なし
vector<int> v(n);   // 1次元, n個の要素
vector<int> v(n,d); // 1次元, n個の要素, 値'd'で初期化
vector<vector<int> > vv();   // 2次元, 要素数指定なし
vector<vector<int> > vv(n);  // 2次元, n行, 列数指定なし
vector<vector<int> > vv(n, vector<int>(m));    // 2次元, n行m列
vector<vector<int> > vv(n, vector<int>(m, d)); // 2次元, n行m列, 値'd'で初期化

// vの末尾にxを追加
v.push_back(x);
// vの末尾の要素を削除
v.pop_back();

// vのサイズを返す
v.size()

// vectorで昇順ソート
sort(v.begin(), v.end());
// vectorで降順ソート
// 降順にしたいときはbegin() とend() の前にrを加える
sort(v.rbegin(), v.rend());

/*
#######################################################################
文字列
#######################################################################
*/

// 文字列反転
reverse(str.begin(), str.end());

// 文字列の抜き出し(i文字目からnバイトの抜き出し)
str.substr(i, n);

/*
#######################################################################
アルゴリズム
#######################################################################
*/

//バケット法
// ABC200C

// ビット全探索
// ABC45C
// ABC128C
// ABC147C
// ABC79C
for (int bit = 0; bit < (1 << N); ++bit)
{
}

// 順列全探索
// ABC145C
// ABC150C
vector<int> ord(N);
for (int i = 0; i < N; i++)
{
    ord[i] = i;
}

do
{

} while (next_permutation(ord.begin(), ord.end()));

