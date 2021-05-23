// 競技プログラムその他で使うチートシート
// ここからコピペして時短しよう

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

// 要素があるかどうか検索
// 返り値は最初に見つかったその要素のイテレータ、見つかった場合はv.end()を返す。
find(v.begin(), v.end(), );

// 2次元配列と特定のキー（列間）でソート
// https://qiita.com/Arusu_Dev/items/c36cdbc41fc77531205c
// 昇順
// 最後の"M"を任意の列番号にして使用
sort(vv.begin(), vv.end(), [](const vector<int> &alpha, const vector<int> &beta) { return alpha[M] < beta[M]; });


/*
#######################################################################
文字列
#######################################################################
*/

// String型のループ
for (int i = 0; i < (int)str.size(); ++i){
}

// 文字列反転
reverse(str.begin(), str.end());

// 文字列の抜き出し(i文字目からnバイトの抜き出し)
str.substr(i, n);

// find関数
// 指定の文字列が文字列の何番目に初めて出現する要素かを返す
string str = "123123";
int a = str.find('1'); // a=0
int b = str.find('0'); // b=npos (or -1)（みつからない場合npos(-1)を返す）
int c = str.find('1', 1); // c=3 （検索開始位置を指定することができる）

/*
#######################################################################
その他
#######################################################################
*/

// double型の整数部のみ取得
// int型にキャストすることで小数点以下を切り落とし
double d;
int i = (int)d;

// 整数の桁数を取得
unsigned GetDigit(unsigned num)
{
    unsigned digit = 0;
    while (num != 0)
    {
        num /= 10;
        digit++;
    }
    return digit;
}

// 割り算の切り上げ
// 割られる数をa、 割る数をbとした時、
int ans = (a + (b - 1)) / b;

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