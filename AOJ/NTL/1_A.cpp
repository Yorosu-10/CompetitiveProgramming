#include <bits/stdc++.h>
typedef long long ll;
typedef long long int lli;
typedef long double ld;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

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

int main()
{
    ll n;
    cin >> n;
    cout << n << ":";

    // 素因数格納配列
    vector<ll> PF;
    PF = PrimeFactorize(n);

    for (auto pf : PF)
    {
        cout << " "  << pf;
    }
    cout << endl;
}