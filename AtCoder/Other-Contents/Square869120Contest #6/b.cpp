#include <bits/stdc++.h>
typedef long long ll;
typedef long long int lli;
typedef long double ld;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main()
{   
    int N;
    cin >> N;

    vector<ll> A(N), B(N);

    rep(i ,N){
        cin >> A[i] >> B[i];
    }

    vector<ll> AA = A;
    vector<ll> BB = B;

    sort(AA.begin(), AA.end());
    sort(BB.begin(), BB.end());

    // 切り上げ
    int num = (N + (2 - 1)) / 2;
    ll IN = AA[num-1];
    ll OUT = BB[num-1];

    ll res = 0;
    rep(i, N)
    {
        res += abs(A[i]-IN);
        res += abs(B[i] - A[i]);
        res += abs(OUT - B[i]);
    }

    cout << res << endl;

    return 0;
}