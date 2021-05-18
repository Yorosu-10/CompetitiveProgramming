#include <iostream>
#include <string>      // string
#include <algorithm>   // min, max, swap
#include <iomanip>　   // setprecision()
#include <cmath>　　　 // pow, sqrt
#include <vector>      // vector
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;
using namespace std;

int main()
{
    int A, B, C;
    long long int X, Y;
    cin >> A >> B >> C >> X >> Y;

    long long int a, b, tmp;
    long long int money = LINF;

    for (long long int ab = 0; ab <= 2 * max(X,Y);++ab){
        // abはABビザを買う枚数
        // ABピザ枚数が決まればAピザ、Bピザ枚数は一意に決まる。
        if ((2 * X - ab)<0){
            a = 0;
        }else{
            // 切り上げ
            a = (2 * X - ab+1) / 2;
        }

        if ((2 * Y - ab) < 0)
        {
            b = 0;
        }
        else
        {
            // 切り上げ
            b = (2 * Y - ab + 1) / 2;
        }

        tmp = A * a + B * b + C * ab;
        if(tmp<money){
            money = tmp;
        }
    }

    cout << money << endl;

    return 0;
}