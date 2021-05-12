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

    // vector
    vector<int> v(N);
    for(int i=0; i<N; i++){
        cin >> v[i];
    }

    // vectorで降順ソート
    sort(v.rbegin(), v.rend());

    // 点
    int Alice = 0;
    int Bob = 0;

    for (int i = 0; i < N; i++)
    {   
        if(i%2==0)
            Alice += v[i];
        else
            Bob += v[i];
    }

    cout << (Alice - Bob) << endl;

    return 0;
}