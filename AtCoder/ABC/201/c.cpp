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
    string S;
    cin >> S;

    int cnt_o = 0, cnt_x=0;

    for (int i = 0; i < 10; ++i)
    {
        if (S[i] == 'o'){
            cnt_o++;
        }
        if (S[i] == 'x')
        {
            cnt_x++;
        }
    }

    int res = 0;

    //string SN;
    //SN += to_string(i);
    vector<int> SN(4);
   
    for (int i = 0; i < (10 - cnt_x); ++i)
    {
        SN[0] = i;
        for (int j = 0; j < (10 - cnt_x); ++j)
        {
            SN[1] = j;
            for (int k = 0; k < (10 - cnt_x); ++k)
            {
                SN[2] = k;
                for (int l = 0; l < (10 - cnt_x); ++l)
                {
                    SN[3] = l;
                    vector<int> flag(cnt_o);
                    for (int o = 0; o < cnt_o; ++o)
                    {
                        int can = 0;
                        for (int ii = 0; ii < 4; ++ii)
                        {
                            if(SN[ii]==o){
                                can = 1;
                                break;
                            }
                        }
                        flag[o] = can;
                    }
                    bool ans_can = true;
                    for (int o = 0; o < cnt_o; ++o)
                    {
                        if(flag[o]==0){
                            ans_can = false;
                            break;
                        }
                    }
                    if(ans_can=true){
                        res++;
                    }
                }
            }
        }
    }

    cout << res << endl;
    return 0;
}