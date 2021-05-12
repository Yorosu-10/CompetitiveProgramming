#include <iostream>
#include <string>      // string
#include <algorithm>   // min, max, swap
#include <iomanip>　   // setprecision()
#include <cmath>　　　 // pow, sqrt
#include <vector>      // vector
using namespace std;

int main()
{

    long long int N;
    int K;
    cin >> N >> K;

    for (int kk = 0; kk < K; ++kk){
        if(N%200==0){
            N = N / 200;
        }else{
            N = N * 1000 + 200;
        }
    }

    cout << N << endl;

    return 0;
}
