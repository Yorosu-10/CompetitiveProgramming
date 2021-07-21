//ABC14-D

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
    int n;
    cin >> n;

    vector<int> imos(1000002, 0);

    int a, b;
    rep(i, 0, n)
    {
        cin >> a >> b;
        imos[a]++;
        // 開区間と閉区間に気を付けて！！
        // 閉区間、つまりa<=x<=bならば...
        imos[b+1]--;
        // 閉区間、つまりa<=x<bならば...
        // imos[b]--;
    }

    // 色0は[1]に対応、色iは[i+1]に対応
    vector<int> color_num(1000002, 0);
    rep(i, 1, 1000002){
        color_num[i] = color_num[i - 1] + imos[i-1];
    }

    int res = 0;
    rep(i, 1, 1000002)
    {
        res = max(res, color_num[i]);
    }

    cout << res << endl;

    return 0;
}