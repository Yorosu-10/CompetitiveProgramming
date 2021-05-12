#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
 
int main(){
    int n;

    cin >> n;

    vector<int> vec(n);

    int min_num=1000000, max_num=-1000000;
    long long int sum=0; 
    
    for(int i=0; i<n; i++){
        cin >> vec[i];
        min_num = min(min_num, vec[i]);
        max_num = max(max_num, vec[i]);
        sum += vec[i];
    }

    cout << min_num << " " << max_num << " " << sum << endl;

    return 0;
}