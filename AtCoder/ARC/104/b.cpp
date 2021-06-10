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
    string S;
    cin >> N;
    cin >> S;

    // [0]は0を代入。
    vector<int> A(N + 1, 0), T(N + 1, 0), C(N + 1, 0), G(N + 1, 0);

    rep(i, 0, N){
        A[i+1] = A[i];
        T[i+1] = T[i];
        C[i + 1] = C[i];
        G[i + 1] = G[i];
        if (S[i] == 'A')
            A[i + 1] += 1;
        if (S[i] == 'T')
            T[i + 1] += 1;
        if (S[i] == 'C')
            C[i + 1] += 1;
        if (S[i] == 'G')
            G[i + 1] += 1;
    }

    int res = 0;

    rep(i, 0, N-1){
        rep(j, i+1, N){
            if ((A[j + 1] - A[i]) == (T[j + 1] - T[i]) && (C[j + 1] - C[i]) == (G[j + 1] - G[i]))
                res++;
        }
    }

    cout << res << endl;

    return 0;
}