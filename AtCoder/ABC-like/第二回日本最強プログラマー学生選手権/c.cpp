#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
#define rep(i, b, e) for (int i = (int)(b); i < (int)(e); i++)
const double PI = acos(-1);
using namespace std;

int A, B;
bool check(int gcd)
{
    int A_cnt = (A - 1) / gcd;
    int B_cnt = B / gcd;
    if ((B_cnt - A_cnt) >= 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{

    cin >> A >> B;

    // GCDの最大値を二分探索する。→ダメ。閾値かどうかはわからない
    // GCDの値はB以下
    int gcd;
    for (gcd = B; gcd > 0; gcd--)
    {
        if (check(gcd))
        {
            break;
        }
    }

    cout << gcd << endl;

    return 0;
}