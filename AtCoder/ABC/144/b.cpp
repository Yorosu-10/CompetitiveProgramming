#include <iostream>
#include <string>      // string
#include <algorithm>   // min, max, swap
#include <iomanip>　   // setprecision()
#include <cmath>　　　 // pow, sqrt
#include <vector>      // vector
using namespace std;

int main()
{
    int N;
    cin >> N;

    bool flag = false;

    for (int i = 9; i > 0;--i){
        if(N%i==0){
            int k = N / i;
            if(1<=k&&k<=9){
                flag = true;
                break;
            }
        }
    }

    if(flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}