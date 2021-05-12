#include <iostream>
#include <string>      // string
#include <algorithm>   // min, max, swap
#include <iomanip>　   // setprecision()
#include <cmath>　　　 // pow, sqrt
#include <vector>      // vector
#include <vector>      // vector
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
using namespace std;

int main()
{
    string S;
    cin >> S;

    int N = S.size();

    int res = 0;
    int tmp = 0;

    for (int i = 0; i <= N; ++i){
        if (S[i] == 'A' || S[i] == 'C' || S[i] == 'G' || S[i] == 'T')
        {
            tmp++;
        }else{
            if(res<tmp){
                res = tmp;
            }
            tmp = 0;
        }
    }

    cout << res << endl;

    return 0;
}