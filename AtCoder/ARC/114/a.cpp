#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const double PI = acos(-1);
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> X(N);
    rep(i, N) cin >> X[i];

    vector<int> P_list{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

    vector<int> v;

    for(auto p : P_list){
        bool flag = false;
        for (int i = 0; i < (int)X.size(); ++i)
        {
            if(X[i]%p==0){
                X[i] = 1;
                flag = true;
            }
        }
        if(flag){
            v.push_back(p);
        }
    }

    int res = 1;
    for (auto vv : v){
        res *= vv;
    }

    cout << res << endl;

    return 0;
}