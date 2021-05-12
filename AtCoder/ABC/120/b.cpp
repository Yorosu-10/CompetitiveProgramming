#include <iostream>
#include <string>      // string
#include <algorithm>   // min, max, swap
#include <iomanip>　   // setprecision()
#include <cmath>　　　 // pow, sqrt
#include <vector>      // vector
using namespace std;

int main()
{
    int A, B, K;
    cin >> A >> B >> K;

    // A, BのうちAの方を小さくする
    if(A>B)
        swap(A, B);
    
    // cntがKに一致したら終了
    int cnt = 0;
    int res;

    for (int i = A; i > 0;--i){
        if(A%i==0&&B%i==0)
            cnt++;
        if(cnt==K){
            res = i;
            break;
        }
    }

    cout << res << endl;

    return 0;
}