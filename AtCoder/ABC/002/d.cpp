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

int count_bits(int bit)
{
    int sum;
    for (sum = 0; bit != 0; bit &= bit - 1)
        sum++;
    return sum;
}

int main()
{
    int N, M;
    cin >> N >> M;

    int x, y;

    vector<vector<bool>> flag(N, vector<bool>(N, 0)); // 2次元, n行m列, 値'd'で初期化
    rep(i, 0, M){
        cin >> x >> y;
        flag[x - 1][y - 1] = 1;
    }

    int res = 0;

    for (int bit = 1; bit < (1 << N); ++bit)
    {
        bool can = true;
        rep(i, 0, N - 1)
        {
            if (bit & (1 << i)){
                rep(j, i + 1, N){
                    if (bit & (1 << j))
                    {
                        if(!flag[i][j])
                            can = 0;
                    }
                }
            }
        }
        
        if(can)
            res = max(res, count_bits(bit));
    }

    cout << res << endl;

    return 0;
}