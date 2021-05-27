#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
#define rep(i, b, e) for (int i = (int)(b); i < (int)(e); i++)
const double PI = acos(-1);
using namespace std;

int main()
{
    int n, m ,q;
    cin >> n;
    vector<int> A(n);
    rep(i, 0, n) cin >> A[i];

    cin >> q;
    rep(i, 0, q){
        cin >> m;
        bool can = false;
        // ビット全探索
        for (int bit = 0; bit < (1 << n); ++bit)
        {
            // 和
            ll sum = 0;
            rep(j, 0, n){
                if (bit & (1 << j)){
                    sum += A[j];
                }
            }
            if(sum==m){
                cout << "yes" << endl;
                can = true;
                break;
            }
        }
        if(!can){
            cout << "no" << endl;
        }
    }

    return 0;
}