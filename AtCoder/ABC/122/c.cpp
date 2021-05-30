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
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;

    // 累積和 // [0]は0を代入
    vector<ll> Sum_cnt(N, 0);
    bool A_flag;

    if (S[0] == 'A')
        A_flag = 1;
    else
        A_flag = 0;
    
    for (int i = 1; i <= N; ++i)
    {
        if(S[i]=='A'){
            A_flag = 1;
        }
        if (A_flag && S[i] != 'C' && S[i] != 'A')
        {
            A_flag = 0;
        }
        if (A_flag && S[i] == 'C')
        {
            A_flag = 0;
            Sum_cnt[i] = Sum_cnt[i - 1] + 1;
            continue;
        }
        
        Sum_cnt[i] = Sum_cnt[i - 1];
    }

    int l, r;
    rep(i, 0, Q){
        cin >> l >> r;
        --l;
        --r;
        cout << (Sum_cnt[r] - Sum_cnt[l]) << endl;
    }

    return 0;
}