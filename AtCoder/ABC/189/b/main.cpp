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

// 浮動小数点の誤差に注意する
int main()
{
    int N, X;
    cin >> N >> X;
    X *= 100;

    ll alco=0;
    int V, P;
    rep(i, 0, N)
    {
        cin >> V >> P;
        alco += V * P;
        if(alco>X){
            cout << (i + 1) << endl;
            return 0;
        }
    }

    cout << "-1" << endl;
    return 0;
}