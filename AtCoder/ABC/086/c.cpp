#include <iostream>
#include <string>      // string
#include <algorithm>   // min, max, swap
#include <iomanip>     // setprecision()
#include <cmath>       // pow, sqrt
#include <vector>      // vector
using namespace std;

int main()
{
    long long int N, tmp_t, tmp_x, tmp_y;
    cin >> N;

    vector<long long int> t;
    vector<long long int> x;
    vector<long long int> y;

    for(int i=0; i<N; i++){
        cin >> tmp_t >> tmp_x >> tmp_y;
        t.push_back(tmp_t);
        x.push_back(tmp_x);
        y.push_back(tmp_y);
    }

    bool can = true;

    long long int ti = 0;
    long long int xi = 0;
    long long int yi = 0;

    for (int i = 0; i < N; i++)
    {
        if(!can)
            break;

        long long int dt = abs(t[i] - ti);
        long long int dx = abs(x[i] - xi);
        long long int dy = abs(y[i] - yi);

        if (dt - dx - dy >= 0 && (dt - dx - dy)%2==0){
            can = true;
        }
        else
        {
            can = false;
        }

        ti = t[i];
        xi = x[i];
        yi = y[i];

    }

    if (can)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}