#include <bits/stdc++.h>
typedef long long ll;
typedef long long int lli;
typedef long double ld;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
using namespace std;

int main()
{
    lli A, B, C;
    cin >> A >> B >> C;

    if((pow(A,2)+pow(B,2))<pow(C,2)){
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}