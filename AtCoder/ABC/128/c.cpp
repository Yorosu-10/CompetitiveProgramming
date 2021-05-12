#include <iostream>
#include <string>      // string
#include <algorithm>   // min, max, swap
#include <iomanip>     // setprecision()
#include <cmath>       // pow, sqrt
#include <vector>      // vector
using namespace std;

int main(){

    int N, M;
    cin >> N >> M;

    vector< vector<int> > vv(M);

    for(int i=0; i<M; ++i){
        int k;
        cin >> k;
        for(int j=0; j<k; ++j){
            int a;
            cin >> a;
            --a;
            vv[i].push_back(a);
        }
    }

    vector<int> p(M);

    for (int i = 0; i < M; ++i)
    {
        cin >> p[i];
    }

    int res=0;

    for(int bit=0; bit<(1<<N); ++bit){
        bool can = true;
        for (int i = 0; i < M; ++i){
            int num = 0;
            for (auto v : vv[i])
            {
                if(bit & (1<<v))
                    ++num;
            }
            if((num%2)!=p[i])
                can = false;
        }
        if(can)
            ++res;
    }

    cout << res << endl;
    return 0;
}