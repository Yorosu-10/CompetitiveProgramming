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

// ビットに何個のフラグが立っているか
int count_bits(int bit)
{
    int sum;
    for (sum = 0; bit != 0; bit &= bit - 1)
        sum++;
    return sum;
}

int main()
{
    int N;

    cin >> N;

    if (N % 2 != 0)
        return 0;

    for (int bit = (1 << N) - 1; bit > 0; --bit)
    {
        if (count_bits(bit) != (N / 2))
            continue;

        int left = 0, right = 0;

        bool can = true;

        for (int i = 0; i < N; ++i)
        {
            if (bit & (1 << i))
            {
                if (left == 0)
                {
                    can = false;
                    break;
                }
                ++right;
                --left;
            }
            else
            {
                ++left;
            }
        }

        if (can)
        {
            for (int i = 0; i < N; ++i)
            {
                if (bit & (1 << i))
                {
                    cout << ")";
                }
                else
                {
                    cout << "(";
                }
            }
            cout << endl;
        }
    }
    return 0;
}