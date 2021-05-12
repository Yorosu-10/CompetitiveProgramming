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
    string S;
    cin >> S;

    int res = 0;

    for (int i = 0; i < (int)S.size()-2; i++)
    {
        if(S[i]!='A')
            continue;

        if(S[i+1] != 'B')
            continue;

        if(S[i + 2] != 'C')
            continue;

        ++res;
    }

    cout << res << endl;
    return 0;
}