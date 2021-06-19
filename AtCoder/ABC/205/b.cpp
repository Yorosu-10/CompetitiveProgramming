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
    int N;
    cin >> N;
    vector<bool> flag(N, false);

    int a;

    bool can = true;

    rep(i, 0, N){
        cin >> a;
        --a;

        if(!flag[a]){
            flag[a] = true;
        }
        else
        {
            can = false;
            break;
        }
    }

    if(!can){
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }

    return 0;
}