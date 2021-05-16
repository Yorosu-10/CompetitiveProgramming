#include <bits/stdc++.h>
using namespace std;
int N, k;

int main(){
/*
#######################################################################
全探索
#######################################################################
*/
    //バケット法
    // ABC200C

    // ビット全探索 
    // ABC45C, ABC128C, ABC147C, ABC79C, ABC197C
    for (int bit = 0; bit < (1 << N); ++bit)
    {
    }

    // 3次元ビット全探索
    // ABC31D 
    int len[10];
    for (int bit = 0; bit < pow(3, k); ++bit)
    {
        int tmp = bit;
        // 3進数への変換 // 2進数と違い自分で変換しなくてはならない
        for (int pos = 1; pos <= k; ++pos)
        {   
            len[pos] = tmp % 3;
            tmp /= 3;
        }
    }

    // 順列全探索
    // ABC145C, ABC150C
    vector<int> ord(N);
    for (int i = 0; i < N; i++)
    {
        ord[i] = i;
    }

    do
    {

    } while (next_permutation(ord.begin(), ord.end()));

    // 再帰関数を用いた全探索（DFS）
    // ABC165C, CPSCO2019 Session1 C

}


