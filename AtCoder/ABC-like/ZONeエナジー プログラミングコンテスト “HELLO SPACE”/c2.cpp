#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
#define rep(i, b, e) for (int i = (int)(b); i < (int)(e); i++)
const double PI = acos(-1);
using namespace std;

int N;
vector<ll> A, B, C, D, E;

bool check(ll score){
    // 重複を許さない
    set<int> s;
    // 数値>=scoreなら1、数値<scoreなら0に情報を圧縮
    rep(i, 0 ,N){
        int bit = 0;
        if(A[i]>=score)
            bit += 1;
        if (B[i] >= score)
            bit += 2;
        if(C[i]>= score)
            bit += 4;
        if(D[i] >= score)
            bit += 8;
        if(E[i] >= score)
            bit += 16;
        s.insert(bit);
    }
    // 能力セットから3人選んでくる
    for(auto si : s){
        for(auto sj : s){
            for(auto sk : s)
            {
                int bit_ = si | sj | sk;
                if (bit_ == ((1 << 5) - 1))
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    cin >> N;
    ll a, b, c, d, e;

    rep(i, 0, N){
        cin >> a >> b >> c >> d >> e;
        A.push_back(a);
        B.push_back(b);
        C.push_back(c);
        D.push_back(d);
        E.push_back(e);
    }

    // その最大値が達成可能ならば、OK
    // その最大値が達成不可能ならば、NG
    ll ng = INF+1;
    ll ok = 0;
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