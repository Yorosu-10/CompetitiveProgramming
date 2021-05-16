#include <bits/stdc++.h>
typedef long long ll;
typedef long long int lli;
typedef long double ld;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
using namespace std;

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
    lli N;
    cin >> N;
    
    // digitは0スタートとする
    int digit = GetDigit(N) -1;

    int digit_3 = digit / 3;

    lli comma=0;

    for (int d = 0; d < digit_3;d++){
        comma += d * (pow(1000, d+1) - pow(1000, d));
    }

    comma += (N - pow(1000, digit_3)+1) * digit_3;

    cout << comma << endl;

    return 0;
}