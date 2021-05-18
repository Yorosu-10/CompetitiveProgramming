#include <iostream>
#include <string>      // string
#include <algorithm>   // min, max, swap
#include <iomanip>　   // setprecision()
#include <cmath>　　　 // pow, sqrt
#include <vector>      // vector
using namespace std;

string divide[4] = {"dream", "dreamer", "erase", "eraser"};

// 後ろから見ていく。
int main()
{
    string str;
    cin >> str;

    // 文字列配列を逆順に
    reverse(str.begin(), str.end());
    for (int i = 0; i<4; i++)
        reverse(divide[i].begin(), divide[i].end());

    bool can = true;

    for(int i=0; i<str.size();){
        bool can2 = false;
        for (int j = 0; j < 4; j++){
            if (str.substr(i, divide[j].size()) == divide[j])
            {
                i += divide[j].size();
                can2 = true;
            }
        }
        if (can2 == false){
            can = false;
            break;
        }
    }

    if(can){
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}