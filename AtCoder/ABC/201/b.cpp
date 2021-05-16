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
    vector<string> S(N);
    vector<int> T(N);

    for (int i = 0; i < N;++i){
        cin >> S[i] >> T[i];
    }

    // 一番高い高さh1, 2番目h2
    // 一番高い高さのindexはindex1, 2番目はindex2
    int h1 = 0, h2 = 0;
    int index1, index2;

    for (int i = 0; i < N;++i){
        if(T[i]>h1){
            index2 = index1;
            h2 = h1;
            h1 = T[i];
            index1 = i;
        }else{
            if(T[i]>h2){
                h2 = T[i];
                index2 = i;
            }
        }
    }

    cout << S[index2] << endl;

    return 0;
}