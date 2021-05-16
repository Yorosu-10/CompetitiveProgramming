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

    int res = 0;

    for (int i = 1; i <= N;i=i+2){
        int count = 0;
        for (int j = 1; j <= i;++j){
            if(i%j==0){
                count++;
            }
        }
        if(count==8){
            res++;
        }
    }

    cout << res << endl;
    return 0;
}