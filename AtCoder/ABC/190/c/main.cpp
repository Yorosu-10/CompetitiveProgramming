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
    int N, M;
    cin >> N >> M;

    vector<int> A(M), B(M); // 1次元, n個の要素
    rep(i, 0, M){
        cin >> A[i] >> B[i];
        A[i]--;
        B[i]--;
    }

    int K;
    cin >> K;

    vector<int> C(K), D(K); // 1次元, n個の要素
    rep(i,0,K){
        cin >> C[i] >> D[i];
        --C[i];
        --D[i];
    }

    // 皿に置かれているか否か
    // 初期値はfalse
    vector<bool> dish(N);

    int res = 0;

    for (int bit = 0; bit < (1 << K); ++bit)
    {
        rep(i, 0, N){
            dish[i] = false;
        }
        rep(i, 0, K){
            // ビットが立っていたら皿Cに、立っていなかったら皿Dに置く
            if(bit&(1<<i)){
                dish[C[i]] = true;
            }else{
                dish[D[i]] = true;
            }
        }

        int tmp = 0;
        rep(i, 0, M)
        {
            if (dish[A[i]] && dish[B[i]]){
                tmp++;
            }
        }
        res = max(tmp, res);
    }

    cout << res << endl;

    return 0;
}