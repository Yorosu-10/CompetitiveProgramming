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
    int N;
    ll X;
    cin >> N >> X;

    ll a;
    vector<ll> A; // 1次元, 要素数指定なし
    rep(i, 0, N)
    {
        cin >> a;
        if(a!=X)
            A.push_back(a);
    }

    // ループ
    for (int i = 0; i < (int)A.size(); ++i)
    {
        cout << A[i];
        if(i!=(int)A.size()-1){
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}