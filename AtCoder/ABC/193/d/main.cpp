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

int pow10(int n){
    int res = 1;
    rep(i, 0, n){
        res *= 10;
    }
    return res;
}

int main()
{
    int K;
    cin >> K;

    string S, T;
    cin >> S >> T;

    vector<int> A_Card_cnt(9, 0);
    vector<int> B_Card_cnt(9, 0);

    for (int i = 0; i < (int)S.size(); ++i)
    {
        for (int j = 0; j < 9;++j)
        {
            if(S[i]=='0'+j+1){
                A_Card_cnt[j]++;
            }
        }
    }

    for (int i = 0; i < (int)T.size(); ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            if (T[i] == '0' + j + 1)
            {
                B_Card_cnt[j]++;
            }
        }
    }

    // 全探索
    ll win_case = 0;
    vector<int> A_Card_cnt_ref = A_Card_cnt;
    vector<int> B_Card_cnt_ref = B_Card_cnt;

    // 高橋の5枚目
    rep(i, 0, 9){
        // 初期化
        A_Card_cnt = A_Card_cnt_ref;
        B_Card_cnt = B_Card_cnt_ref;

        A_Card_cnt[i]++;
        // カード上限枚数に抵触していないか？
        if (A_Card_cnt[i] + B_Card_cnt[i] > K)
            continue;

        ll A_score = 0;
        rep(ii,0,9){
            A_score += pow10(A_Card_cnt[ii]) * (ii + 1);
        }

        ll Ci = K - (A_Card_cnt[i] - 1) - B_Card_cnt[i];

        // 青木の5枚目
        rep(j, 0, 9){
            // 初期化
            B_Card_cnt = B_Card_cnt_ref;

            B_Card_cnt[j]++;
            // カード上限枚数に抵触していないか？
            if (A_Card_cnt[j] + B_Card_cnt[j] > K)
                continue;           

            ll B_score = 0;
            rep(jj, 0, 9)
            {
                B_score += pow10(B_Card_cnt[jj]) * (jj + 1);
            }

            ll Cj = K - A_Card_cnt[j] - (B_Card_cnt[j]-1);

            if(A_score>B_score)
                win_case = win_case + Ci * Cj;
        }
    }

    ld res = (ld)win_case / (9 * K - 8) / (9 * K - 8 -1);

    cout << fixed << setprecision(15);
    cout << res << endl;

    return 0;
}