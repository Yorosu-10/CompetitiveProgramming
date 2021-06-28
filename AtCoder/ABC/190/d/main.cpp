#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
#define rep(i, b, e) for (int i = (int)(b); i < (int)(e); i++)
const double PI = acos(-1);
using namespace std;
using Graph = vector<vector<int>>;

int main()
{
    ll tmp;
    cin >> tmp;
    const ll N = tmp;

    ll res = 0;

    for (int n = 1; n <= sqrt(2*N);++n){
        ll tmp = (2*N) % n;
        if (tmp != 0)
            continue;

        int m = 2* N / n;
        if((m-n+1)%2==0)
            res++;
    }

    cout << 2* res << endl;

    return 0;
}