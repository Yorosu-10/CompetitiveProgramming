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

int TimeToSecond(string s){
    int h, m, sec;

    h = (s[0] - '0') * 10 + (s[1] - '0');
    m = (s[3] - '0') * 10 + (s[4] - '0');
    sec = (s[6] - '0') * 10 + (s[7] - '0');

    int res = (3600 * h + 60 * m + sec);

    return res;
}

int main()
{
    int n;
    string s1, s2;
    vector<int> imos(86401);
    // 0秒は[1]に対応、i秒は[i+1]に対応
    vector<int> train(86401);
    while (cin >> n)
    {
        if(n==0)
            break;

        rep(i, 0, 86401){
            imos[i] = 0;
            train[i] = 0;
        }

        rep(i,0,n){
            cin >> s1 >> s2;
            int b = TimeToSecond(s1);
            int e = TimeToSecond(s2);
            imos[b]++;
            imos[e]--;
        }

        rep(i, 1, 86401)
        {
            train[i] = train[i - 1] + imos[i - 1];
        }

        int res = 0;
        rep(i, 1, 86401)
        {
            res = max(res, train[i]);
        }

        cout << res << endl;
    }
    return 0;
}