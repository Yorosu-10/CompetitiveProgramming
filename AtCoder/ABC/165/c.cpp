#include <bits/stdc++.h>
typedef long long ll;
typedef long long int lli;
typedef long double ld;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
using namespace std;

// https://yamakasa.net/atcoder-abc-165-c/

vector<int> A(11, 0);
int N, M, Q;
lli score = 0;
vector<vector<int>> vv(4); // 2次元, n行, 列数指定なし

void dfs(int n)
{
    // 終了条件
    if(n==N){
        lli d_sum = 0;
        for (int i = 0; i < Q; ++i)
        {
            if(A[vv[1][i]] - A[vv[0][i]] == vv[2][i])
            {
                d_sum += vv[3][i];
            }
        }
        if(score<d_sum){
            score = d_sum;
        }
        return;
    }

    // 配列A[]を全探索していく。
    for (int a = min(A[n], M); a <= M;++a){
        A[n + 1] = a;
        dfs(n + 1);
    }
}

int main()
{
    
    cin >> N >> M >> Q;

    lli a, b, c, d;
    for (int q=0;q<Q;++q)
    {
        cin >> a >> b >> c >> d;
        vv[0].push_back(a);
        vv[1].push_back(b);
        vv[2].push_back(c);
        vv[3].push_back(d);
    }

    // 0番目はダミー
    A[0] = 1;
    dfs(0);

    cout << score << endl;

    return 0;
}