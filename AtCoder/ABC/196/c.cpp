#include <bits/stdc++.h>
typedef long long ll;
typedef long long int lli;
typedef long double ld;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
using namespace std;

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

int main()
{
    // 最大桁は12桁
    lli N;
    cin >> N;

    lli cnt = 0;

    for (int i = 1; i <= 999999;++i){
        int digit = GetDigit(i);
        lli num = pow(10, digit) * i + i;
        if(num<=N)
            cnt++;
    }

    cout << cnt << endl;

    return 0;
}