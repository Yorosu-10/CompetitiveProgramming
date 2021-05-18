#include <iostream>
#include <string>      // string
#include <algorithm>   // min, max, swap
#include <iomanip>　   // setprecision()
#include <cmath>　　　 // pow, sqrt
#include <vector>      // vector
using namespace std;

int main()
{
    int A, B, C, X;
    cin >> A >> B >> C >> X;
    int c = 0;

    for(int i=0; i<=A; i++){
        if(500*i>X)
            break;
        for (int j = 0; j <= B; j++){
            if (100 * j > X-500*i)
                break;
            for (int k = 0; k <= C; k++){
                if(X==(500*i+100*j+50*k))
                    c++;
            }
        }
    }

    cout << c << endl;

    return 0;
}
