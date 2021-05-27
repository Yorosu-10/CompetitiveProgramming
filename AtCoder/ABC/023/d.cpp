#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const double PI = acos(-1);
using namespace std;

ll N;

vector<ll> H, S;

bool check(ll score){
    // 風船0~N-1は点数scoreを達成するためには何秒までに割る必要があるか？
    vector<ll> ballon_sec(N);
    rep(i, N){
        // そのスコアを初期値が達成できない場合は問答無用false
        if(score-H[i]<0)
            return false;
        ballon_sec[i] = (score - H[i]) / S[i];
    }

    // 昇順ソート
    sort(ballon_sec.begin(), ballon_sec.end());

    // 時間制約が厳しいものから割っていく。
    rep(i, N){
        // 現在の時刻はi秒、上回ってしまったらアウト
        if (ballon_sec[i] < i){
            return false;
        }
    }

    return true;
}

int main()
{
    cin >> N;
    ll h, s;

    rep(i, N)
    {
        cin >> h >> s;
        H.push_back(h);
        S.push_back(s);
    }

    // その最小値が達成可能ならば、OK
    // その最小値が達成不可能ならば、NG
    ll ng = 0;
    ll ok = LINF;
    while (abs(ng - ok) > 1)
    {
        ll mid = (ok + ng) / 2;
        if (check(mid))
            ok = mid;
        else
            ng = mid;
    }

    cout << ok << endl;

    return 0;
}