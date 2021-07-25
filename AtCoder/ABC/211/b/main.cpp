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
    string s;

    vector<bool> cycle(4, false);
    rep(i, 0, 4)
    {
        cin >> s;
        if(s=="H")
            cycle[0] = true;
        else if (s == "2B")
            cycle[1] = true;
        else if (s == "3B")
            cycle[2] = true;
        else if (s == "HR")
            cycle[3] = true;
    }

    bool can = true;
    rep(i, 0, 4){
        if(cycle[i]==false)
            can = false;
    }

    if(can)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}