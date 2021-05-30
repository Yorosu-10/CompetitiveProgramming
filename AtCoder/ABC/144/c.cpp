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
    ll N;
    cin >> N;

    ll yakusu;

    for (yakusu = (ll)sqrt(N); 1 <= yakusu; --yakusu){
        if(N%yakusu==0)
            break;
    }

    ll another_yakusu = N / yakusu;

    cout << (yakusu + another_yakusu - 2) << endl;

    return 0;
}