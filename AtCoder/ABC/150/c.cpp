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

    vector<int> P(N), Q(N);

    for (int i = 0; i < N;++i){
        cin >> P[i];
    }

    for (int i = 0; i < N; ++i){
        cin >> Q[i];
    }

    int a,b;
    int cnt = 0;

    vector<int> ord(N);
    for (int i = 0; i < N; i++){
        ord[i] = i + 1;
    }

    do
    {
        cnt++;
        bool flag_p = true, flag_q = true;
        for (int i = 0; i < N; i++){
            if(ord[i]!=P[i])
            {
                flag_p = false;
            }
            if(ord[i]!=Q[i])
            {
                flag_q = false;
            }
        }
        if (flag_p==true){
            a = cnt;
        }
        if (flag_q == true)
        {
            b = cnt;
        }
    } while (next_permutation(ord.begin(), ord.end()));

    cout << abs(a - b) << endl;

    return 0;
}