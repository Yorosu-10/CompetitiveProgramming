#include <bits/stdc++.h>
typedef long long ll;
typedef long long int lli;
typedef long double ld;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
using namespace std;

bool check_length(int K, int N, vector<int> len, vector<string> v , vector<string> w)
{
    bool flag = true;
    for (int i = 0; i < N; ++i)
    {
        string vv=v[i];
        string ww=w[i];
        int length = 0;
        for (int j = 0; j < (int)vv.size(); ++j)
        {
            length += len[(vv[j] - '0')];
        }
        if(length!=(int)ww.size()){
            flag = false;
            break;
        }
    }
    return flag;
}

bool check_moji(int K, int N, vector<int> len, vector<string> v, vector<string> w)
{
    bool flag=true;

    vector<string> moji(9, "");

    for (int i = 0; i < N; ++i)
    {
        string vv=v[i];
        string ww=w[i];
        int pos = 0;
        for (int j = 0; j < (int)vv.size(); ++j)
        {
            int length = len[(vv[j] - '0')];
            string str = ww.substr(pos, length);
            if(moji[vv[j]]=="")
                moji[vv[j]] == str;
            if(moji[vv[j]] != str ){
                flag == false;
                break;
            }

            pos += length;
        }
    }
    if(flag==true){
        for (int i = 0; i < K; ++i){
            cout << moji[i] << endl;
        }
    }
}

// まずは1~9に割り当たる長さ(1~3)を全探索する
// 長さに矛盾がなければ、文字に矛盾がないか調べる。
int main()
{
    int K, N;
    cin >> K >> N;

    vector<string> v(N);
    vector<string> w(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> v[i] >> w[i];
    }

    // 各数字のlengthを格納する
    vector<int> len(9);

    for (int bit = 0; bit < pow(3, K); ++bit)
    {
        int tmp = bit;
        for (int i = 0; i < K; ++i)
        {
            len[i] = tmp % 3 + 1; // 1~3文字に
            tmp /= 3;
        }

        bool flag_len = check_length(K, N, len, v, w);
        if (flag_len == false)
        {
            continue;
        }

        bool flag_moji = check_moji(K, N, len, v, w);
        if(flag_moji==false){
            continue;
        }else{
            break;
        }
    }
    return 0;
}