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

    int century;

    if (N % 100 == 0)
    {
        century = N / 100;
    }
    else
    {
        century = (N / 100) + 1;
    }

    cout << century << endl;

    return 0;
}