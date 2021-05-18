#include <iostream>
#include <string>      // string
#include <algorithm>   // min, max, swap

#include <iomanip>　   // setprecision()
#include <cmath>　　　 // pow, sqrt
#include <vector>      // vector

using namespace std;

int main()
{
    string str;
    cin >> str;

    int c = 0;

    for (int i=0; i<(int)str.size(); i++){
        if(str[i]=='1')
            c++;
    }

    cout << c << endl;

    return 0;
}
