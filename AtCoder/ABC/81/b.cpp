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
    long long int A[N];
    for(int i=0; i<N; i++){
        cin >> A[i];
    }

    bool flag = true;
    int c = 0;

    while(flag){
        for (int i = 0; i < N; i++)
            if(A[i]%2!=0)
                flag=false;
            else
                A[i] = A[i] / 2;
        if (flag == true)
            c++;
    }

    cout << c << endl;

    return 0;
}