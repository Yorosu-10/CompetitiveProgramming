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
    lli N;
    cin >> N;

    // 答えは整数で持つ
    int rootN = sqrt(N);
    int log2N = log2(N);

    // 集合を持つ
    set<lli> Set;

    for (lli b = 2; b <= log2N; ++b)
    {
        lli a = 2;
        while(1)
        {
            lli tmpN = pow(a, b);
            if(tmpN<=N){
                Set.insert(tmpN);
                ++a;
            }else{
                break;
            }
        }
    }

    cout << (N - Set.size()) << endl;

    return 0;
}