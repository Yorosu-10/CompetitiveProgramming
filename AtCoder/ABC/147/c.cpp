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
    int A[20];
    int X[20][20];
    int Y[20][20];
    cin >> N;

    for (int i = 0; i < N;++i)
    {
        cin >> A[i];
        for (int j = 0; j < A[i]; ++j)
        {
            cin >> X[i][j];
            X[i][j]--;
            cin >> Y[i][j];
        }
    }
    // ここからソルバー
    int ans = 0;
    // bit全探索していく
    // とりあえずN人の人がそれぞれ正直者か不親切な人かを仮定するflagを作ってしまう
    for (int bit = 0; bit < (1 << N); ++bit)
    {
    
        bool flag[N];
        for(int i = 0; i < N; ++i)
        {
            if (bit & (1 << i))
                flag[i] = true;
            else
                flag[i] = false;
        }
        // 矛盾がおきていないかをチェックするflag
        bool check = true;
        // 実際に矛盾がないかチェックしていく
        for (int i = 0; i < N; ++i)
        {
            // 不親切な人の場合は無視する
            if (flag[i] == false)
                continue;
            // 実際の証言Yと仮定flagを比較して正直者なはずなのに間違えていれば矛盾フラグをfalseにする
            for (int j = 0; j < A[i]; ++j)
            {
                if (Y[i][j] != flag[X[i][j]])
                    check = false;
            }
        }
        // 正直者が何人いるか数え上げるする変数
        int sums = 0;
        if (check == true)
        {
            for (int i = 0; i < N; ++i){
                sums += flag[i];
                // ansを更新していく
                ans = max(ans, sums);
            }
        }
    }
    // 出力
    cout << ans << endl;
}
