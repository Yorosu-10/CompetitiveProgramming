#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const double PI = acos(-1);
using namespace std;

// わからないので答えを見た。これは難しいと思った。
// https://ikatakos.com/pot/programming_algorithm/contest_history/atcoder/2018/0818_abc106
// https://arcslab.hatenablog.jp/entry/abc106


    int main(void)
    {

        int n, m, q;
        cin >> n >> m >> q;
        int train[501][501] = {};
        int cum[501][501] = {};

        int m1, m2;
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d", &m1, &m2);
            train[m1][m2]++;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cum[i][j] = cum[i][j - 1] + train[i][j];
            }
        }

        int a, b;
        int answer;
        for (int i = 0; i < q; i++)
        {
            answer = 0;
            scanf("%d%d", &a, &b);
            for (int j = a; j <= b; j++)
            {
                answer += cum[j][b];
            }
            printf("%d\n", answer);
        }

        return 0;
    }
