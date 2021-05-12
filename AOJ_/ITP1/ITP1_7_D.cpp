#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m, l;

    cin >> n >> m >> l;

    vector< vector<long long int> > A(n, vector<long long int>(m));
    vector< vector<long long int> > B(m, vector<long long int>(l));
    vector< vector<long long int> > C(n, vector<long long int>(l));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> A[i][j];
        }
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<l; j++){
            cin >> B[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<l; j++){
            C[i][j]=0;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<l; j++){
            for(int k=0; k<m; k++){
                C[i][j]+=A[i][k]*B[k][j];
            }
            if(j!=l-1) cout << C[i][j] << " ";
            else if(j==l-1) cout << C[i][j] << endl;
        }
    }

    return 0;

}