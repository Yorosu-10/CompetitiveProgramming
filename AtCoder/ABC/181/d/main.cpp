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
    string S;
    cin >> S;

    // 2桁以下の場合
    if ((int)S.size() == 1)
    {
        int n = stoi(S);
        if(n==8)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        return 0;
    }

    if ((int)S.size() == 2){
        int n = (S[0] - '0') * 10 + (S[1] - '0');
        int m = (S[1] - '0') * 10 + (S[0] - '0');

        if(n%8==0 || m%8==0)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        
        return 0;
    }

    vector<int> num(10, 0);
    for (char c : S)
    {
        num[c - '0']++;
    }

    vector<int> num_tmp(10);

    //111 ~ 999まで探索する
    //百の位
    for (int i = 1; i <= 9; ++i)
    {
        //十の位
        for (int j = 1; j <= 9; ++j){
            //一の位
            for (int k = 1; k <= 9; ++k)
            {
                rep(ii, 0, 10)
                    num_tmp[ii] = 0;

                num_tmp[i]++;
                num_tmp[j]++;
                num_tmp[k]++;

                int n = 100 * i + 10 * j + k;
                if(n%8!=0)
                    continue;

                bool flag = true;
                rep(ii, 0, 10)
                {
                    if(num_tmp[ii] > num[ii])
                        flag = false;
                }
                if (flag){
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "No" << endl;

    return 0;
}