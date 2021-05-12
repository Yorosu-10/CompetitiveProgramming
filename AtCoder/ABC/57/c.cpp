#include <iostream>
#include <string>      // string
#include <algorithm>   // min, max, swap
#include <iomanip>　   // setprecision()
#include <cmath>　　　 // pow, sqrt
#include <vector>      // vector
using namespace std;

unsigned GetDigit(unsigned num)
{
    unsigned digit = 0;
    while (num != 0)
    {
        num /= 10;
        digit++;
    }
    return digit;
}

int main()
{
    long long int N, A, B;
    int ans;
    cin >> N;

    // int型にキャストすることで小数点以下を切り落とし
    long long int maxA = (long long int)sqrt(N);

    for (A = maxA; A > 0; --A)
    {
        if(N%A==0){
            B = N / A;
            ans = GetDigit(B);
            break;
        }else{
            continue;
        }
    }

    cout << ans << endl;

    return 0;
}