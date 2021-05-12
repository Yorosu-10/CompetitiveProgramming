#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
 
int main(){
    int n;

    cin >> n;

    vector<int> vec(n);

    for(int i=0; i<n; i++){
        cin >> vec[i];
    }

    for(int i=n-1; i>0; i--){
        cout << vec[i] << " ";
    }
    cout << vec[0] << endl;

    return 0;

}