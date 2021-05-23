#include <bits/stdc++.h>
typedef long long ll;
typedef long long int lli;
typedef long double ld;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main()
{
    string S;
    cin >> S;

    for (int i = (int)S.size()-1; 0<=i; --i)
    {
        if(S[i] == '6'){
            cout << '9';
        }
        else if (S[i] == '9'){
            cout << '6';
        }
        else
        {
            cout << S[i];
        }
    }

    cout << endl;

    return 0;
}