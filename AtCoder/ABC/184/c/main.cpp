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

bool check(ll r1, ll c1, ll r2, ll c2){
    if (r1 - 2 <= r2 && r2 <= r1 + 2 && c1 - 2 <=c2 && c2 <= c1 + 2){
        return true;
    }
    if(c1==c2){
        if (r1 - 3 == r2 || r1 + 3 == r2)
            return true;
    }
    if (r1 == r2){
        if (c1 - 3 == c2 || c1 + 3 == c2)
            return true;
    }

    return false;
}

int main()
{
    ll r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    ll dif_x = r2 - r1;
    ll dif_y = c2 - c1;

    if(r1 == r2 && c1 == c2){
        cout << "0" << endl;
        return 0;
    }
    if(check(r1, c1, r2, c2) || abs(dif_x)==abs(dif_y)){
        cout << "1" << endl;
        return 0;
    }

    // 斜め移動を使わず2手でいける点
    // かつ1, 0手ではいけない点
    for (int r = -4; r <= 4; ++r)
    {
        for (int c = -4; c <= 4; ++c){
            if(dif_x==r && dif_y==c){
                cout << "2" << endl;
                return 0;
            }
        }
    }
    for (int r = -2; r <= 2; ++r){
        if (dif_x == r && abs(dif_y)==5){
            cout << "2" << endl;
            return 0;
        } 
    }
    for (int c = -2; c <= 2; ++c)
    {
        if (dif_y == c && abs(dif_x) == 5)
        {
            cout << "2" << endl;
            return 0;
        }
    }
    if(abs(dif_x)==6 && dif_y==0){
        cout << "2" << endl;
        return 0;
    }
    if (abs(dif_y) == 6 && dif_x == 0)
    {
        cout << "2" << endl;
        return 0;
    }

    ll r3, c3;
    if ((abs(dif_x) + abs(dif_y)) % 2 == 1)
    {
        ll tmp = abs(dif_x) + abs(dif_y);
        tmp = tmp / 2;
        if(dif_x > 0)
            r3 = r1 + tmp;
        else
            r3 = r1 - tmp;

        if (dif_y > 0)
            c3 = c1 + tmp;
        else
            c3 = c1 - tmp;

        if (!check(r3, c3, r2, c2))
        {
            cout << "3" << endl;
            return 0;
        }
    }
    
    cout << "2" << endl;
    

    return 0;
}