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
    cin >> N;

    ll A;
    set<ll> Set;

    // ll 型の番地に int 型の変数を記録する場合
    // 値xが配列Aの中に何個存在するか
    map<ll, ll> cnt;

    rep(i, 0, N)
    {
        cin >> A;
        Set.insert(A);
        cnt[A]++;
    }

    ll res = N*(N-1)/2;

    for(auto a : Set){
        res -= (cnt[a] * (cnt[a] - 1)) / 2;
    }

    cout << res << endl;

    return 0;
}