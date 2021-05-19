#include <iostream>
#include <string>      // string
#include <algorithm>   // min, max, swap
#include <iomanip>　   // setprecision()
#include <cmath>　　　 // pow, sqrt
#include <vector>      // vector
#include <vector>      // vector
typedef long long ll;
typedef long long int lli;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
using namespace std;

int N, K;
int res=10000;

vector<lli> A(32);

// 購入する物品の金額を格納する配列
vector<lli> v(6);

// 金額から必要枚数を計算する関数
int coin_num(lli money){
    int coin = 0;
    string str = to_string(money);
    for (int i = 0; i < (int)str.size(); ++i)
    {
        if ((str[i]-'0') >= 5)
            coin += (str[i] - '0') - 4;
        else
            coin += (str[i] - '0');
    }
    return coin;
}

// nはdfs関数コール数（繰り返し数）に相当する
// indexは今回用いるindex番号を示す
void dfs(int n, int index)
{
    // 終了条件 // K個選び終えたら終了 
    if(n==K){
        // 終了時処理
        // 合計金額を計算
        lli sum = 0;
        for (int i = 0; i < K; ++i)
        {
            sum += v[i];
        }
        int coin = coin_num(sum);

        if(coin<res){
            res = coin;
        }

        return;
    }

    for (int i = index; i < N;++i){
        v[n] = A[i];
        dfs(n + 1, i+1);
    }
}

int main()
{
    
    cin >> N >> K;

    for (int i = 0; i < N;++i)
    {
        cin >> A[i];
    }

    dfs(0, 0);

    cout << res << endl;

    return 0;
}