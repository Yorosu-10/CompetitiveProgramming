#include <bits/stdc++.h>
typedef long long ll;
typedef long long int lli;
typedef long double ld;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main()
{
    int A, B, W;
    cin >> A >> B >> W;

    // 切り捨て
    int max_num = (W * 1000) / A;

    // 切り上げ
    int min_num = ((W * 1000+(B-1)) / B);

    if(min_num <= max_num)
        cout << min_num << " " << max_num << endl;
    else
        cout << "UNSATISFIABLE" << endl;

    return 0;
}