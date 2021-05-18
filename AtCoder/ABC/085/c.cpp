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
    long long int Y;
    cin >> N >> Y;

    int x, y, z;

    bool flag = false;

    int x_max = Y / 10000;
    int y_max;

    for (x = 0; x <= x_max; x++)
    {
        y_max = (Y - 10000 * x) / 5000;
        for (y = 0; y <= y_max; y++)
        {
            z = (Y - 10000 * x - 5000 * y) / 1000;

            if(N-x-y == z){
                flag = true;
                break;
            }
        }
        if(flag) break;
    }

    if(flag==true){
        cout << x << " " << y << " " << z <<endl;
    }
    else{
        cout << -1 << " " << -1 << " " << -1 << endl;
    }

    return 0;
}