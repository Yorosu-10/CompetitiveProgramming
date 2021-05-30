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
    int a, b, c;

    cin >> a >> b >> c;
    if(a==b){
        cout << c << endl;
        return 0;
    } 

    if(b==c){
        cout << a << endl;
        return 0;
    }

    if(c==a){
        cout << b << endl;
        return 0;
    }

    cout << "0" << endl;

    return 0;
}