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

// 2点(x1, y1), (x2, y2)間の距離を返す
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
    int N;
    cin >> N;

    double x0, y0;
    double x_, y_;

    cin >> x0 >> y0;
    cin >> x_ >> y_;

    // 中心
    double xo, yo;
    xo = (x0 + x_) / (double)2;
    yo = (y0 + y_) / (double)2;

    // 辺の長さ
    double l;
    l = Distance(x0, y0, xo, yo);

    // 中心を(0,0)に平行移動する。p0を平行移動する。
    x0 -= xo;
    y0 -= yo;

    x0 /= l;

    double theta;
    // acosは0~piの間の値を返す。
    theta = acos(x0);

    if(y0>=0){
        // スルー
    }else{
        theta = 2 * M_PI - theta;
    }

    double x1, y1;
    x1 = l* cos(theta+2*M_PI/N);
    y1 = l* sin(theta + 2 * M_PI / N);

    // 平行移動を戻す
    x1 += xo;
    y1 += yo;

    // 出力を小数第〇位まで出力。この後に普通にcoutすればOK。
    cout << fixed << setprecision(11);

    cout << x1 << " " << y1 << endl;

    return 0;
}