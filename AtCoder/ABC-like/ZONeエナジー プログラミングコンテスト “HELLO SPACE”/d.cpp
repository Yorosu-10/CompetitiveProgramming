#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
#define rep(i, b, e) for (int i = (int)(b); i < (int)(e); i++)
const double PI = acos(-1);
using namespace std;

int main()
{
    string angou, T_ans;
    cin >> angou;

    deque<char> T;

    // 反転はO(N)なので間に合わない
    // 反転のフラグを持っておき、反転中は後ろに文字を付け加えていく。
    bool r_flag = 0;

    for (int i = 0; i < (int)angou.size(); ++i)
    {
        if (angou[i] == 'R')
        {
            if(r_flag)
                r_flag = 0;
            else
                r_flag = 1;
        }
        else
        {
            if(r_flag){
                T.push_front(angou[i]);
            }
            else
            {
                T.push_back(angou[i]);
            }
        }
    }
    // 最後に反転フラグが立ってれば実際に反転させる
    if(r_flag)
        reverse(T.begin(), T.end());

    for (int i = 0; i < (int)T.size(); ++i)
    {

        // T_ansの末尾要素と追加したい要素が一致しない場合と、
        // 現在T_ansが空の場合のみ普通に追加
        if (T_ans.empty())
        {
            T_ans.push_back(T[i]);
            continue;
        }
        if (T[i] != T_ans.back())
        {
            T_ans.push_back(T[i]);

        // T_ansの末尾要素と追加したい要素が一致する場合は追加しないし、末尾要素を削除する。
        }
        else
        {
            T_ans.pop_back();
        }
    }

    cout << T_ans << endl;

    return 0;
}