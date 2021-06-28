// https://kengo92i.hatenablog.jp/entry/2014/08/30/233011

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <ctime>
#include <cstring>
#include <numeric>

#define ALL(v) (v).begin(), (v).end()
#define REP(i, p, n) for (int i = p; i < (int)(n); ++i)
#define rep(i, n) REP(i, 0, n)
#define dump(a) (cerr << #a << "=" << (a) << endl)
#define DUMP(list)          \
    cout << "{ ";           \
    for (auto nth : list)   \
    {                       \
        cout << nth << " "; \
    }                       \
    cout << "}" << endl;

using namespace std;

const int MAX = INT_MAX;

int N, M;
int dp[20001][256];

vector<int> C;
vector<int> x;

int round255(int n)
{
    if (n > 255)
    {
        return 255;
    }
    else if (n < 0)
    {
        return 0;
    }
    else
    {
        return n;
    }
}

int main()
{
    while (cin >> N >> M && N)
    {
        C.resize(M);
        x.resize(N);
        fill_n((int *)dp, sizeof(dp) / sizeof(int), MAX);

        rep(i, M) { cin >> C[i]; }
        rep(i, N) { cin >> x[i]; }

        dp[0][128] = 0;

        rep(i, N)
        {
            rep(j, 256)
            {
                if (dp[i][j] == MAX)
                {
                    continue;
                }
                rep(k, M)
                {
                    int yn = j + C[k];
                    yn = round255(yn);
                    int sum2 = (x[i] - yn) * (x[i] - yn);
                    dp[i + 1][yn] = min(dp[i + 1][yn], dp[i][j] + sum2);
                }
            }
        }

        cout << *min_element(dp[N], dp[N] + 256) << endl;
    }
    return 0;
}