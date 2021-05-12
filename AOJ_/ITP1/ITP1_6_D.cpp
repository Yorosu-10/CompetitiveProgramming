#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n, m;

    cin >> n >> m;

    vector< vector<int> > A(n, vector<int>(m));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> A[i][j]; 
        }
    }

    vector<int> b(m);

    for(int j=0; j<m; j++){
        cin >> b[j]; 
    }

    vector<int> c(n);

    for(int i=0; i<n; i++){
        c[i]=0;

        for(int j=0; j<m; j++){
            c[i]+=A[i][j]*b[j]; 
        }
        cout << c[i] << endl;
    }

    return 0;

}