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
    ll A, B, C;
    cin >> A >> B >> C;

    if(A>=0 && B>=0)
    {
        if(A>B)
            cout << ">" << endl;
        else if(A<B)
            cout << "<" << endl;
        else if(A==B)
            cout << "=" << endl;
    }
    else if (A < 0 && B >= 0)
    {
        if (C % 2 == 0)
        {
            if (abs(A) > B)
                cout << ">" << endl;
            else if (abs(A) < B)
                cout << "<" << endl;
            else if (abs(A) == B)
                cout << "=" << endl;
        }
        else
        {
            cout << "<" << endl;
        }
    }
    else if (A >= 0 && B < 0)
    {
        if (C % 2 == 0)
        {
            if (A > abs(B))
                cout << ">" << endl;
            else if (A < abs(B))
                cout << "<" << endl;
            else if (A == abs(B))
                cout << "=" << endl;
        }
        else
        {
            cout << ">" << endl;
        }
    }
    else if (A<0 && B <0)
    {
        if (C % 2 == 0)
        {
            if (A < B)
                cout << ">" << endl;
            else if (A > B)
                cout << "<" << endl;
            else if (A == B)
                cout << "=" << endl;
        }
        else
        {
            if (A > B)
                cout << ">" << endl;
            else if (A < B)
                cout << "<" << endl;
            else if (A == B)
                cout << "=" << endl;
        }
    }

    return 0;
}