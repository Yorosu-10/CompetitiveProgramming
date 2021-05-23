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
    ll a, b, x;
    cin >> a >> b >> x;

    double theta;

    if(x>=(double)(a*a*b)/2.0){
        theta = atan((double)2 * (a * a * b - x) / (a * a * a));
    }else{
        theta = acos((double)2 * x / (a*b*b));
    }

    // 出力を小数第〇位まで出力。この後に普通にcoutすればOK。
    cout << fixed << setprecision(10);

    cout << (180 * theta / PI) << endl;
}