// 競技プログラムその他で使うチートシート
// ここからコピペして時短しよう
#include <bits/stdc++.h>

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
vector<int> v;    // 1次元, 要素数指定なし
vector<int> v(n);   // 1次元, n個の要素
vector<int> v(n,d); // 1次元, n個の要素, 値'd'で初期化
vector<vector<int> > vv;   // 2次元, 要素数指定なし
vector<vector<int> > vv(n);  // 2次元, n行, 列数指定なし
vector<vector<int> > vv(n, vector<int>(m));    // 2次元, n行m列
vector<vector<int> > vv(n, vector<int>(m, d)); // 2次元, n行m列, 値'd'で初期化

// ループ
for (int i = 0; i < (int)v.size(); ++i)
{
}

// 関数の引数に使うときは参照渡しすると値が更新されて返ってくる
void func(vector<int> &v){
}
// ->普通にコールすればよい
func(v);

// vの末尾にxを追加
v.push_back(x);
// vの末尾の要素を削除
v.pop_back();

// vのサイズを返す
v.size()

// 配列反転 // O(N)かかることに注意！
reverse(v.begin(), v.end());

// 一次元vector初期化
v.assign(N, 0); // nは要素数
// 二次元vector初期化
vv.assign(n_rows, vector<int>(n_cols, value)); // n_rowsは行数、n_colsは列数

// vectorで昇順ソート
sort(v.begin(), v.end());
// vectorで降順ソート
// 降順にしたいときはbegin() とend() の前にrを加える
sort(v.rbegin(), v.rend());

// 要素があるかどうか検索
// 返り値は最初に見つかったその要素のイテレータ、見つかった場合はv.end()を返す。
find(v.begin(), v.end(), );

// Vectorの最小値のイテレータを取得
auto iter = min_element(v.begin(), v.end());
// Vectorの最小値のindexを取得
auto index = min_element(v.begin(), v.end()) - v.begin();
// Vectorの最小値を取得
auto min_val = *min_element(v.begin(), v.end());

// Vectorの最大値のイテレータを取得
auto iter = max_element(v.begin(), v.end());
// Vectorの最大値のindexを取得
auto index = max_element(v.begin(), v.end()) - v.begin();
// Vectorの最大値を取得
auto min_val = *max_element(v.begin(), v.end());

/*
#######################################################################
pair
#######################################################################
*/

// pair配列宣言
vector<pair<int, int>> p(N);
// .first, .secondを使って代入
rep(i, 0, N)
{
    cin >> p[i].first;
    p[i].second = i;
}
// ソート <.firstの要素でソートされる>
sort(p.begin(), p.end());

/*
#######################################################################
priority_queue
#######################################################################
*/
// int 型の要素を持ち、最も小さい値を取り出す形の priority_queue を定義する場合
priority_queue<int, vector<int>, greater<int>> Q1;

// double 型の要素を持ち、最も小さい値を取り出す形の priority_queue を定義する場合
priority_queue<double, vector<double>, greater<double>> Q2;

// int 型の要素を持ち、最も大きい値を取り出す形の priority_queue を定義する場合
priority_queue<int, vector<int>, less<int>> Q3;

/*
#######################################################################
データ構造
#######################################################################
*/

// deque
// 先頭からも末尾からも追加するようなデータ構造

// 宣言
deque<char> deq;

// 末尾にxを追加
deq.push_back(x);
// 先頭にxを追加
deq.push_front(x);

// 末尾の要素を削除
deq.pop_back();

// 要素を全削除
deq.clear();

// その他vectorやstringで使えるメソッドは使える。

/*
#######################################################################
set
#######################################################################
*/

// 宣言
set<int> Set;

// 集合Setに要素xを追加する。
// 但し、既にxが集合Setにある場合は追加しない。
Set.insert(x);
// 集合Setから要素xを削除する。
Set.erace(x);

// 集合Setを空にする。
Set.clear();

// forループ
for(auto x : Set){

}

/*
#######################################################################
map
#######################################################################
*/

// 宣言
// 最初は値がすべて 0（文字列の場合は空文字列）で初期化されている

// int 型の番地に int 型の変数を記録する場合
map<int, int> M1;
// int 型の番地に string 型の変数を記録する場合
map<int, string> M2;
// string 型の番地に double 型の変数を記録する場合
map<string, double> M3;

/*
#######################################################################
文字列
#######################################################################
*/

// String型のループ
for (int i = 0; i < (int)str.size(); ++i)
{
}

// 文字列反転  // O(N)かかることに注意！
reverse(str.begin(), str.end());

// 文字列のi文字目以降の取り出し(0はじまり)
str.substr(i);

// 文字列の抜き出し(i文字目からnバイトの抜き出し)
str.substr(i, n);

// find関数
// 指定の文字列が文字列の何番目に初めて出現する要素かを返す
string str = "123123";
int a = str.find('1'); // a=0
int b = str.find('0'); // b=npos (or -1)（みつからない場合npos(-1)を返す）
int c = str.find('1', 1); // c=3 （検索開始位置を指定することができる）

// stringの要素（str[i]）は(多分)char型

/*
#######################################################################
文字列 <=> 数値
#######################################################################
*/

// string to 数値
	stox( ) //ただしxは変換したい型によって変わる
// 数値　to string
    to_string(i)
// char to int 
    int(c-'0')
// int to char
    '0' + i


/*
#######################################################################
整数論
#######################################################################
*/

// double型
// 小数点以下を切り落とし
double d;
int i = (int)d;
int i = floor(d);
// 小数点以下を切り上げ
int i = (int)(d + 0.9);
int i = ceil(d);

// 割り算の切り上げ
// 割られる数をa、 割る数をbとした時、
int ans = (a + (b - 1)) / b;

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

// 最大公約数
long long gcd(long long a, long long b)
{
    if (a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}

// 最小公倍数
long long lcm(long long a, long long b)
{
    return a*b / gcd(a, b);
}

// nCkを求める（n=60くらい以下でないとオーバーフローするので注意, 60はOK）
long long combi(long long n, long long k)
{
    long long r = 1;
    for (long long d = 1; d <= k; ++d)
    {
        r *= n--;
        r /= d;
    }
    return r;
}

/*
#######################################################################
幾何学
#######################################################################
*/

// 2点(x1, y1), (x2, y2)間の距離を返す
long double Distance(long double x1, long double y1, long double x2, long double y2){
    long double d;
    long double dx = x1 - x2;
    long double dy = y1 - y2;
    d = sqrt(dx*dx+dy*dy);
    return d;
}

/*
#######################################################################
que
#######################################################################
*/

// queの全要素を削除
while (!que.empty())
    que.pop();


/*
その他
*/