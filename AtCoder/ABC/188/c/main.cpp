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

    ll A, max_A=0, max_B=0;
    int index_A, index_B;
    rep(i, 1, (1 <<(N-1))+1)
    {
        cin >> A;
        if(max_A<A){
            max_A = A;
            index_A = i;
        }
    }
    rep(i, (1<<(N - 1))+1, (1<<N)+1)
    {
        cin >> A;
        if (max_B < A)
        {
            max_B = A;
            index_B = i;
        }
    }

    if(max_A<max_B)
        cout << index_A << endl;
    else
        cout << index_B << endl;

    return 0;
}