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
    ll K;
    cin >> N >> K;

    vector<pair<int, int>> p(N);
    rep(i, 0, N){
        cin >> p[i].first;
        p[i].second = i;
    }

    sort(p.begin(), p.end());

    ll all = K/N;
    ll rem = K % N;

    vector<ll> okashi(N);
    rep(i, 0, N){
        if(i<rem){
            okashi[p[i].second] = all+1;
        }else{
            okashi[p[i].second] = all;
        }
    }

    rep(i, 0, N){
        cout << okashi[i] << endl;
    }
    return 0;
}