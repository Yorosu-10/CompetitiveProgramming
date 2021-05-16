#include <bits/stdc++.h>
typedef long long ll;
typedef long long int lli;
typedef long double ld;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
using namespace std;

int main()
{
    lli N;
    cin >> N;

    int res = 0;

    for (int i = 1; i <= 9; ++i)
    {
        if (i <= N)
        {
            res++;
        }
        else
        {
            break;
        }
    }
    for (int i = 100; i <= 999; ++i)
    {
        if (i <= N)
        {
            res++;
        }
        else
        {
            break;
        }
    }
    for (int i = 10000; i <= 99999; ++i)
    {
        if (i <= N)
        {
            res++;
        }
        else
        {
            break;
        }
    }

    cout << res << endl;

    return 0;
}