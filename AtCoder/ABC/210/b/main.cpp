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
    string S;
    cin >> S;

    for (int i = 0; i < (int)S.size(); ++i)
    {
        if(S[i]=='1'){
            if(i%2==0){
                cout << "Takahashi" << endl;
            }
            else
            {
                cout << "Aoki" << endl;
            }
            break;
        }
    }

    return 0;
}