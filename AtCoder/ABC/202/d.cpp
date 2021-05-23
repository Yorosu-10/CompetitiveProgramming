#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

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

int main()
{
    int a, b;
    ll k;
    cin >> a >> b >> k;

    string str="";

    int n=a + b;
    rep(i, n){
        if (a > 0 && k <= combi(a + b - 1, b))
        {
            a--;
            str+="a";
        }
        else
        {
            if(b>0){
                k -= combi(a + b - 1, b);
                b--;
                str += "b";
            }
        }
    }

    cout << str << endl;

    return 0;
}