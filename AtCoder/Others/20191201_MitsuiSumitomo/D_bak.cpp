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

    // 0~9
    vector<int> counter(10, 0);

    int num;
    string Str = "";
    // Sから3文字以上の数字重複を削除した文字列Strを作成
    // Strのsizeは最大10*3
    for (int i = 0; i < N; ++i)
    {   
        // 数字取得
        num = S[i] - '0';
        counter[num]++;
        if(counter[num]<=3){
            Str = Str + S[i];
        }
    }

    /// 000~999が存在するか
    vector<int> flag(1000, 0);

    int size = (int)Str.size();

    for (int i = 0; i < size; ++i)
    {
        for (int j = i+1; j < size; ++j)
        {
            for (int k = j+1; k < size; ++k)
            {
                num = (Str[i]-'0') * 100 + (Str[j]-'0') * 10 + (Str[k]-'0');
                if(flag[num]==0){
                    flag[num] = 1;
                }
            }
        }
    }

    int res = 0;
    for (int i = 0; i < 1000; ++i)
    {
        res += flag[i];
    }

    cout << res << endl;
    return 0;
}