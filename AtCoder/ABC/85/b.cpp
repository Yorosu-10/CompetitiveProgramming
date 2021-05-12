#include <iostream>
#include <string>      // string
#include <algorithm>   // min, max, swap
#include <iomanip>　   // setprecision()
#include <cmath>　　　 // pow, sqrt
#include <vector>      // vector
using namespace std;

/* バケット法 */

int main()
{
    int N;
    cin >> N;

    vector<int> d(N);
    for (int i = 0; i < N; i++){
        cin >> d[i];
    }

    // バケットを用意 // 0で初期化
    vector<int> n(101, 0);

    for (int i = 0; i < N; i++){
        n[d[i]] = 1;
    }

    int ans = 0;
    for (int i = 0; i <= 100; i++)
    {
        if(n[i]==1){
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
