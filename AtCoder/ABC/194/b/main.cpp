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

    vector<int> A(N), B(N);

    rep(i, 0, N){
        cin >> A[i] >> B[i];
    }

    int res = INF;

    rep(i, 0, N){
        rep(j, 0, N){  
            if(i==j){
                res = min(res, A[i]+B[j]);
            }else{
                res = min(res, max(A[i], B[j]));
            }
        }
    }

    cout << res << endl;
    return 0;
}