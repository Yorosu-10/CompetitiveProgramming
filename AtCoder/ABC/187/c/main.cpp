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

    map<string, int> Map;

    string S;
    int code;
    bool can = true;
    rep(i, 0, N)
    {
        cin >> S;
        if(S[0] == '!'){
            code = 2;
            S=S.substr(1);
        }
        else
        {
            code = 1;
        }

        if ((code == 1 && Map[S]!=code) || (code == 2 && Map[S] != code))
            Map[S] += code;

        if(Map[S]==3){
            can = false;
            break;
        }
    }

    if(can){
        cout << "satisfiable" << endl;
    }
    else
    {
        cout << S << endl;
    }
    return 0;
}