#include <iostream>
#include <string>      // string
#include <algorithm>   // min, max, swap
#include <iomanip>　   // setprecision()
#include <cmath>　　　 // pow, sqrt
#include <vector>      // vector
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int> > vv(N, vector<int>(N, 0));

    int a, b;

    for (int i = 0; i < M; ++i)
    {
        cin >> a >> b;
        a = a - 1;
        b = b - 1;
        vv[a][b] = 1;
        vv[b][a] = 1;
    }

    int res = 0;
    
    vector<int> ord(N);
    for (int i = 0; i < N; i++)
    {
        ord[i] = i;
    }

    do
    {   
        // 1からスタートするもの以外考えない
        if(ord[0]!=0)
            break;

        bool flag = true;
        for (int i = 0; i < N-1; i++)
        {
            if (vv[ord[i]][ord[i + 1]] == 0)
            {
                flag = false;
                break;
            }
        }
        if(flag==true){
            res++;
        }
    } while (next_permutation(ord.begin(), ord.end()));

    cout << res << endl;

    return 0;
}