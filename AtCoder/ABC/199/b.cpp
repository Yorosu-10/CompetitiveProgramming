#include <bits/stdc++.h>
typedef long long ll;
typedef long long int lli;
typedef long double ld;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
using namespace std;

int main()
{
    int N;
    cin >> N;

    int A, B;

    int min=0, max=1001;
    for (int i = 0; i < N; ++i)
    {
        cin >> A;
        if(min<A){
            min = A;
        }
    }
    for (int i = 0; i < N; ++i)
    {
        cin >> B;
        if(max>B){
            max = B;
        }
    }

    if(max>=min){
        cout << (max - min + 1) << endl;
    }else{
        cout << '0' << endl;
    }

    return 0;
}