#include <bits/stdc++.h>
typedef long long ll;
typedef long long int lli;
typedef long double ld;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
using namespace std;

int N;

vector<int> v(10);

// nはdfs関数コール数（繰り返し数）に相当する
// mojiは今まで使った文字種類数
void dfs(int n, int moji)
{
    n++;
    //終了条件
    if(n==N){
        for (int i = 0; i < N; ++i)
        {
            char c = 'a' + v[i];
            cout << c;
        }
        cout << endl;
        return;
    }

    for (int i = 0; i <= moji;++i){
        v[n] = i;
        if (i != moji)
        {
            dfs(n, moji);
        }
        else
        {
            dfs(n,moji+1);
        }
    }
}

int main()
{
    cin >> N;

    // a->0, b->1, c->2...と対応づける
    v[0] = 0;
    dfs(0, 1);
    
    cout << endl;

    return 0;
}