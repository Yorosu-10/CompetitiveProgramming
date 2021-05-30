#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
#define rep(i, b, e) for (int i = (int)(b); i < (int)(e); i++)
const double PI = acos(-1);
using namespace std;
using Graph = vector<vector<int>>;

int main()
{
    int N;
    cin >> N;

    vector<vector<int> > cute(3);  // 2次元, n行, 列数指定なし

    ll cu;
    char color;
    rep(i, 0, 2*N)
    {
        cin >> cu;
        cin >> color;

        if(color == 'R'){
            cute[0].push_back(cu);
        }else if(color == 'G'){
            cute[1].push_back(cu);
        }else if(color == 'B'){
            cute[2].push_back(cu);
        }
    }

    // vectorで昇順ソート
    rep(i, 0, 3)
        sort(cute[i].begin(), cute[i].end());

    int a=(int)cute[0].size();
    int b = (int)cute[1].size();
    int c = (int)cute[2].size();

    // 奇数のときtrue, 偶数のときfalse
    bool judge_a = a % 2;
    bool judge_b = b % 2;
    bool judge_c = c % 2;

    // 全部偶数なら
    if(!judge_a && !judge_b && !judge_c){
        cout << "0" << endl;
        return 0;
    }

    ll fuman = LINF;
    ll tmp;

    // cだけ偶数なら
    if(!judge_c){
        // [0]を全探索
        rep(i, 0, a){
            //イテレータを返す
            //見つからなかったらv.end()を返す。
            auto Iter = lower_bound(cute[1].begin(), cute[1].end(), cute[0][i]);
            if (Iter == cute[1].end()){
                tmp = abs(cute[0][i] - cute[1][b - 1]);
                fuman = min(tmp, fuman);
                continue;
            }
            int Index = Iter - cute[1].begin();

            tmp = abs(cute[0][i] - cute[1][Index]);
            fuman = min(tmp, fuman);
            if(Index!=0){
                tmp = abs(cute[0][i] - cute[1][Index-1]);
                fuman = min(tmp, fuman);
            }
        }
    }

    // bだけ偶数なら
    if (!judge_b)
    {
        // [0]を全探索
        rep(i, 0, a)
        {
            //イテレータを返す
            //見つからなかったらv.end()を返す。
            auto Iter = lower_bound(cute[2].begin(), cute[2].end(), cute[0][i]);
            if (Iter == cute[2].end())
            {
                tmp = abs(cute[0][i] - cute[2][c - 1]);
                fuman = min(tmp, fuman);
                continue;
            }
            int Index = Iter - cute[2].begin();

            tmp = abs(cute[0][i] - cute[2][Index]);
            fuman = min(tmp, fuman);
            if (Index != 0)
            {
                tmp = abs(cute[0][i] - cute[2][Index - 1]);
                fuman = min(tmp, fuman);
            }
        }
    }

    // aだけ偶数なら
    if (!judge_a)
    {
        // [1]を全探索
        rep(i, 0, b)
        {
            //イテレータを返す
            //見つからなかったらv.end()を返す。
            auto Iter = lower_bound(cute[2].begin(), cute[2].end(), cute[1][i]);
            if (Iter == cute[2].end())
            {
                tmp = abs(cute[1][i] - cute[2][c - 1]);
                fuman = min(tmp, fuman);
                continue;
            }
            int Index = Iter - cute[2].begin();

            tmp = abs(cute[1][i] - cute[2][Index]);
            fuman = min(tmp, fuman);
            if (Index != 0)
            {
                tmp = abs(cute[1][i] - cute[2][Index - 1]);
                fuman = min(tmp, fuman);
            }
        }
    }

    cout << fuman << endl;

    return 0;
}