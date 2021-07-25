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
    int A, B;
    cin >> A >> B;

    double C;

    C = (A - B) / 3.0 + B;

    // 出力を小数第〇位まで出力。この後に普通にcoutすればOK。
    cout << fixed << setprecision(7);
    cout << C << endl;
    return 0;
}