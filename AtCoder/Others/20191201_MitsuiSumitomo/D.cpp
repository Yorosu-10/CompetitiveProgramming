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
    string S;
    cin >> N;
    cin >> S;

    int res = 0;

    int x, y, z;

    // PIN = xyz
    for (int pin = 0; pin < 1000; ++pin)
    {
        x = pin / 100; // 100の位
        y = (pin - 100 * x) / 10; // 10の位
        z = pin % 10; // 1の位

        int x_index = S.find(x + '0');
        if (x_index==-1)
        {
            continue;
        }
        else
        {
            int y_index = S.find(y + '0', x_index+1);
            if(y_index==-1){
                continue;
            }else{
                int z_index = S.find(z + '0', y_index + 1);
                if(z_index==-1){
                    continue;
                }else{
                    res++;
                }
            }
        }
    }

    cout << res << endl;
    return 0;
}