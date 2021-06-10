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
    vector<int> T(N); // 1次元, 要素数指定なし

    rep(i, 0, N)
        cin >> T[i];

    // vectorで降順ソート
    // 降順にしたいときはbegin() とend() の前にrを加える
    sort(T.rbegin(), T.rend());

    ll time1=0, time2=0;

    rep(i, 0, N){
        if(time1<=time2){
            time1 += T[i];
        }
        else
        {
            time2 += T[i];
        }
    }

    if(time1<=time2){
        cout << time2 << endl;
    }
    else
    {
        cout << time1 << endl;
    }

    return 0;
}