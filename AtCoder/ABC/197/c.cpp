#include <bits/stdc++.h>
typedef long long ll;
typedef long long int lli;
typedef long double ld;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N;++i)
        cin >> A[i];

    lli res = LINF;

    // "間"を定義する。間の数はN-1個ある。
    // 左から0,1,...,N-2と順番をつける。
    // どの間に仕切りがあるのか探索していく。
    // 仕切りなしは許されないので初期値1。
    for (int bit = 1; bit < (1 << N-1); ++bit)
    {   
        int OR_val=A[0], XOR_val=0;
        // 間を1つ1つ見ていく。
        for (int i = 0; i < N - 1;++i){
        
            // 仕切りがあるなら。。。
            if (bit & (1 << i)){
                XOR_val = XOR_val ^ OR_val;
                OR_val = 0;
            }

            OR_val = OR_val | A[i + 1]; // OR計算
        }
        // 最後のA[N-1]番目要素を考慮
        XOR_val = XOR_val ^ OR_val;

        if(XOR_val<res)
            res = XOR_val;
    }

    cout << res << endl;

    return 0;
}