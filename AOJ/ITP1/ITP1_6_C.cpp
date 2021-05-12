#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n, b, f, r, v;

    cin >> n;

    //スペースが必要
    vector< vector< vector<int> > > buildings(4, vector< vector<int> >(3, vector<int>(10)));

    for(int i=0; i<4; i++){
        for(int j=0; j<3; j++){
            for(int k=0; k<10; k++){
                buildings[i][j][k] = 0;
            }
        }
    }

    for(int i=0; i<n; i++){
        cin >> b >> f >> r >> v;
        buildings[b-1][f-1][r-1] += v;
    }

    for(int i=0; i<4; i++){
        for(int j=0; j<3; j++){
            for(int k=0; k<10; k++){
                cout << " " << buildings[i][j][k];
            }
            cout << endl;
        }
        if(i!=3) cout << "####################" << endl;
    }

    return 0;

}