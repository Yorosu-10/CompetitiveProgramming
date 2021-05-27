#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const double PI = acos(-1);
using namespace std;

long double Distance(long double x1, long double y1, long double x2, long double y2)
{
    long double d;
    long double dx = x1 - x2;
    long double dy = y1 - y2;
    d = sqrt(dx * dx + dy * dy);
    return d;
}

int main()
{
    int N, M;
    cin >> N >> M;

    // defined circle
    vector<double> x(N), y(N), r(N);

    // undefined circle
    vector<double> XX(M), YY(M);

    rep(i, N){
        cin >> x[i] >> y[i] >> r[i];
    }
    rep(i, M){
        cin >> XX[i] >> YY[i];
    }

    double r_min = INF;
    double r_tmp;
    rep(i, M)
    {
        rep(j, M){
            if(j==i)
                break;
            r_tmp = Distance(XX[i], YY[i], XX[j], YY[j]) / 2.0;
            r_min = min(r_min, r_tmp);
        }
        rep(j, N){
            r_tmp = Distance(XX[i], YY[i], x[j], y[j]) - r[j];
            r_min = min(r_min, r_tmp);
        }
    }

    if (M == 0)
    {
        rep(i, N){
            r_min = min(r_min, r[i]);
        }
    }

    // 出力を小数第〇位まで出力。この後に普通にcoutすればOK。
    cout << fixed << setprecision(15);

    cout << r_min << endl;

    return 0;
}