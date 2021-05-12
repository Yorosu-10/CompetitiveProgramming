#include <iostream>
#include <string>      // string
#include <algorithm>   // min, max, swap
#include <iomanip>　   // setprecision()
#include <cmath>　　　 // pow, sqrt
#include <vector>      // vector
using namespace std;

int main()
{
    string S;
    cin >> S;

    int bit;
    int bit_ans;

    // 1を+に、0を-に対応させる
    for (int bit = 0; bit < (1 << 3); ++bit){
        int ans = S[0] - '0';
        for (int i = 0; i < 3;++i){
            if (bit & (1 << i)){
                ans += S[1+i] - '0';
            }else{
                ans -= S[1+i] - '0';
            }
        }
        if(ans==7){
            bit_ans = bit;
            break;
        }
    }

    for (int i = 0; i < 3; ++i){
        cout << S[i];
        if (bit_ans & (1 << i))
        {
            cout << '+';
        }
        else
        {
            cout << '-';
        }
    }

    cout << S[3] << '='<< '7' << endl;

    return 0;
}