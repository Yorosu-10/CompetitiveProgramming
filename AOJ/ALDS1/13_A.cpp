#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const double PI = acos(-1);
using namespace std;

void zahyo_update(vector<vector<bool>> &zahyo, int x, int y)
{   
    // 十字をすべてfalseに
    rep(i, 8){
        zahyo[i][y] = false;
        zahyo[x][i] = false;
    }
    
    // 斜め線をfalseに
    for (int i = y-1; i >= 0; --i){
        int def = y - i;
        if(x-def>=0)
            zahyo[x - def][i] = false;
        if(x+def<=7)
            zahyo[x + def][i] = false;
    }
    for (int i = y + 1; i <= 8; ++i)
    {
        int def = i-y;
        if (x - def >= 0)
            zahyo[x - def][i] = false;
        if (x + def <= 7)
            zahyo[x + def][i] = false;
    }

    // 最後にQを置く場所だけはtrueに
    zahyo[x][y] = true;
}

void print_Q(vector<int> ord)
{
    rep(i, 8){
        rep(j, 8){
            if(ord[i]==j)
                cout << "Q";
            else
                cout << ".";
        }
        cout << endl;
    }
}

int main()
{
    int k;
    cin >> k;
    vector<int> r(k), c(k);
    rep(i, k) cin >> r[i] >> c[i];

    vector<int> ord(8);
    for (int i = 0; i < 8; i++)
        ord[i] = i;

    // 順列全探索をしていく
    // ord={8, 1, 2, 4...}のときは
    // クイーンを(0, 8), (1, 1), (2, 2), (3, 4)と置くと対応づける
    do
    {
        bool can = true;
        //条件のQ配置と合致してなければすぐ抜ける
        rep(i, k){
            if(ord[r[i]]!=c[i])
                can=false;
        }

        if(!can)
            continue;

        // その場所にクイーンが置けるか否か
        vector<vector<bool>> zahyo(8, vector<bool>(8, true));

        // 0行目のQから配置していく
        rep(i, 8){
            // 配置するQ座標は(i, ord[i])
            // その場所に配置してもよいのか確認する
            if (zahyo[i][ord[i]] == false)
            {
                can = false;
                break;
            }

            // 座標情報を更新
            zahyo_update(zahyo, i, ord[i]);

            // 0~i-1行目の配置済みのQが大丈夫か見る
            int j_max = i;
            rep(j, j_max)
            {
                if(zahyo[j][ord[j]]==false){
                    can = false;
                }
            }
            if(!can)
                break;
        }

        if(can){
            print_Q(ord);
            break;
        }

    } while (next_permutation(ord.begin(), ord.end()));

    return 0;
}