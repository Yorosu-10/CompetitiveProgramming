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
    string S;
    cin >> N >> S;

    vector<int> E_cnt(N), W_cnt(N);

    // 初期値代入
    if(S[0]=='W'){
        W_cnt[0] = 1;
    }
    else
    {
        W_cnt[0] = 0;
    }

    if(S[N-1]=='E'){
        E_cnt[N - 1] = 1;
    }else{
        E_cnt[N - 1] = 0;
    }

    rep(i, 1, N){
        if(S[i] == 'W')
            W_cnt[i] = W_cnt[i - 1] + 1;
        else
            W_cnt[i] = W_cnt[i - 1];
    }

    for (int i = N - 2; i >= 0; --i)
    {
        if (S[i] == 'E')
            E_cnt[i] = E_cnt[i + 1] + 1;
        else
            E_cnt[i] = E_cnt[i + 1];
    }

    int res=INF;

    rep(i, 0, N){
        res = min(res, (E_cnt[i] + W_cnt[i] - 1));
    }

    cout << res << endl;

    return 0;
}