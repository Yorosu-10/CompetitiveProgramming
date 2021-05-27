#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const double PI = acos(-1);
using namespace std;

bool check_pin(string str, vector<bool> num_use)
{
    bool can=true;
    for (int i = 0; i < (int)str.size(); ++i)
    {
        if (str[i] == 'o'){
            if(!num_use[i]){
                can = false;
                return can;
            }
        }
        else if (str[i] == 'x')
        {
            if (num_use[i])
            {
                can = false;
                return can;
            }
        }
    }

    return can;
}

int main()
{
    string str;
    cin >> str;

    int res = 0;

    // PIN=0000~9999を全探索
    for (int p = 0; p <= 9999; ++p){
        int pin = p;
        // 0~9の数字がPINに使われているか否かのフラグ
        vector<bool> num_use(10, false);
        rep(i, 4){
            num_use[pin % 10] = true; // 各位の数
            pin /= 10;
        }
        if (check_pin(str, num_use)==true)
            res++;
    }

    cout << res << endl;

    return 0;
}