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
    vector<int> x(N), y(N);
    for (int i = 0;i<N;++i){
        cin >> x[i] >> y[i];
    }

    long double sum = 0;
    int cnt = 0;

    vector<int> ord(N);
    for (int i = 0; i < N;i++){
        ord[i] = i;
    }
        
    do{
        cnt++;
        for (int i = 0; i < N - 1; i++)
        {
            int a = ord[i];
            int b = ord[i + 1];
            long double xx = x[b] - x[a];
            long double yy = y[b] - y[a];
            sum += sqrt(pow(xx, 2) + pow(yy, 2));
        }
    } while (next_permutation(ord.begin(), ord.end()));

    long double ave = sum / cnt;

    // 出力を小数第〇位まで出力。この後に普通にcoutすればOK。
    cout << fixed << setprecision(10);
    cout << ave << endl;

    return 0;
}
