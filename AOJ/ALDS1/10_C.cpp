// http://www.cs.t-kougei.ac.jp/SSys/LCS.htm

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
    int q;
    cin >> q;

    string X, Y;

    rep(i, 0, q){
        cin >> X >> Y;
        vector<vector<int>> LCS((int)X.size() + 1, vector<int>((int)Y.size() + 1, 0));

        for (int x = 1; x <= (int)X.size(); ++x)
        {
            for (int y = 1; y <= (int)Y.size(); ++y)
            {
                if(X[x-1] == Y[y-1]){
                    LCS[x][y] = LCS[x-1][y-1] + 1;
                }
                else
                {
                    LCS[x][y] = max(LCS[x - 1][y], LCS[x][y - 1]);
                }
            }
        }

        cout << LCS[(int)X.size()][(int)Y.size()] << endl;
    }
    return 0;
}