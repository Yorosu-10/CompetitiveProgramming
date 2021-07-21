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
    vector<string> s(N);

    // string 型の番地に vector 型の変数を記録する場合
    map<string, vector<int>> begin;

    rep(i, 0, N){
        cin >> s[i];
        string tmp = s[i].substr(0, 3);
        begin[tmp].push_back(i);
    }

    // siが一発勝負ありワードか否か
    vector<bool> ippatsu(N, false);

    vector<string> ends(N);

    rep(i, 0, N)
    {
        string end = s[i].substr((int)s[i].size()-3, 3);
        ends[i] = end;
        if (begin[end].empty())
        {
            ippatsu[i] = true;
        }
    }

    rep(i, 0, N){
        if(ippatsu[i]){
            cout << "Takahashi" << endl;
        }
        else
        {
            vector<int> words = begin[ends[i]];
            bool aoki = false;
            for (auto j : words)
            {
                if(ippatsu[j])
                    aoki = true;
            }
            if(aoki){
                cout << "Aoki" << endl;
            }else{
                cout << "Draw" << endl;
            }
        }
    }

    return 0;
}