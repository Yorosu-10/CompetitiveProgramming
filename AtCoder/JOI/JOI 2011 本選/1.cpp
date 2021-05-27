#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const double PI = acos(-1);
using namespace std;

int main()
{
    int M, N, K;
    cin >> M >> N >> K;

    vector<string> str(M);

    rep(i, M) cin >> str[i];
    
    // 二次元累積和 // [0][0]は0を代入
    vector<vector<int> > Sum_J(M+1, vector<int>(N+1, 0));
    vector<vector<int>> Sum_O(M+1, vector<int>(N + 1, 0));
    vector<vector<int>> Sum_I(M+1, vector<int>(N + 1, 0));

    for (int i = 0; i < M; ++i){
        for (int j = 0; j < N; ++j){
            Sum_J[i + 1][j + 1] = Sum_J[i][j + 1] + Sum_J[i + 1][j] - Sum_J[i][j];
            Sum_O[i + 1][j + 1] = Sum_O[i][j + 1] + Sum_O[i + 1][j] - Sum_O[i][j];
            Sum_I[i + 1][j + 1] = Sum_I[i][j + 1] + Sum_I[i + 1][j] - Sum_I[i][j];
            if (str[i][j] == 'J')
                Sum_J[i+1][j+1] += 1;
            if (str[i][j] == 'O')
                Sum_O[i+1][j+1] += 1;
            if (str[i][j] == 'I')
                Sum_I[i+1][j+1] += 1;
        }
    }

    int a, b, c, d;
    rep(i, K)
    {
        cin >> a >> b >> c >> d;
        a--;
        b--;
        c--;
        d--;
        int res_j, res_o, res_i;

        res_j = Sum_J[c + 1][d + 1] + Sum_J[a][b] - Sum_J[c + 1][b] - Sum_J[a][d + 1];
        res_o = Sum_O[c + 1][d + 1] + Sum_O[a][b] - Sum_O[c + 1][b] - Sum_O[a][d + 1];
        res_i = Sum_I[c + 1][d + 1] + Sum_I[a][b] - Sum_I[c + 1][b] - Sum_I[a][d + 1];

        cout << res_j << " " << res_o << " " << res_i << endl;
    }

    return 0;
}