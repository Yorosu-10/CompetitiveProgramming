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
    vector<int> a(3) ;
    cin >> a[0] >> a[1] >> a[2];

    bool can=false;

    if((a[2]-a[1])==(a[1]-a[0])){
        cout << "Yes" << endl;
        return 0;
    }

    if ((a[1] - a[2]) == (a[2] - a[0]))
    {
        cout << "Yes" << endl;
        return 0;
    }

    if ((a[2] - a[0]) == (a[0] - a[1]))
    {
        cout << "Yes" << endl;
        return 0;
    }

    if ((a[0] - a[2]) == (a[2] - a[1]))
    {
        cout << "Yes" << endl;
        return 0;
    }

    if ((a[1] - a[0]) == (a[0] - a[2]))
    {
        cout << "Yes" << endl;
        return 0;
    }

    if ((a[0] - a[1]) == (a[1] - a[2]))
    {
        cout << "Yes" << endl;
        return 0;
    }

    cout << "No" << endl;

    return 0;
}