#include <bits/stdc++.h>
typedef long long ll;
typedef long long int lli;
typedef long double ld;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main()
{
    lli N;
    cin >> N;
    vector<lli> c(401);

    rep(i, N){
        int tmp;
        cin >> tmp;
        c[tmp + 200]++;
    }

    lli sum = 0;

    for (int i = 0; i < 401;++i){
        int a1 = i - 200;
        for (int j = i + 1; j < 401; ++j)
        {
            int a2 = j - 200;
            sum += (c[i] * c[j] * (a1 - a2) * (a1 - a2));
        }
    }

    cout << sum << endl;

    return 0;
}