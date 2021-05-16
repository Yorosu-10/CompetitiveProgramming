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
    lli N, Q;
    cin >> N;
    string S;
    cin >> S;
    cin >> Q;

    int T;
    lli A, B;

    // 反転しているか否かのフラグ
    // flag=1(反転)、flag=0(順)
    bool flag = 0;

    for (int q = 0; q < Q; ++q)
    {
        cin >> T >> A >> B;
        A = A - 1;
        B = B - 1;

        if (T == 2)
        {
            if (flag == 0)
                flag = 1;
            else
                flag = 0;
        }

        if (T == 1)
        {
            if (flag == 0)
            {
                swap(S[A], S[B]);
            }
            else
            {
                if (A < N)
                    A = A + N;
                else
                    A = A - N;

                if (B < N)
                    B = B + N;
                else
                    B = B - N;

                swap(S[A], S[B]);
            }
        }
    }
    if (flag == 1)
    {
        for (int i = 0; i < N; ++i)
            swap(S[i], S[i + N]);
    }
    cout << S << endl;
}