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

bool check(int sinsu, int n){
    int d = 1;
    while (d<n){
        d *= sinsu;
    }
    bool can = true;
    while (d!=1)
    {
        d /= sinsu;
        int a = n / d;
        if(a==7){
            can = false;
            break;
        }
        n %= d;
    }

    return can;
}

int main()
{
    int N;
    cin >> N;

    int cnt = 0;
    rep(n, 1, N + 1)
    {
        if(check(8, n) && check(10, n)){
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}