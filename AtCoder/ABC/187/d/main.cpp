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
    ll A, B;

    vector<ll> diff(N); // 1次元, n個の要素
    ll sumA = 0;

    rep(i, 0, N){
        cin >> A >> B;
        diff[i] = 2 * A + B;
        sumA += A;
    }

    sort(diff.rbegin(), diff.rend());
    int cnt = 0;
    ll sumDiff = 0;
    rep(i, 0, N)
    {
        cnt++;
        sumDiff += diff[i];
        if(sumDiff>sumA)
            break;
    }

    cout << cnt << endl;
    return 0;
}