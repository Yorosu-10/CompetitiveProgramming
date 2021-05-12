#include <iostream>
 
using namespace std;
 
int main(){
    int N = 3;

    int arr[N];
    for(int i = 0; i<N; i++){
        cin >> arr[i];
    }

    // バブルソート
    int tmp;
    for(int i = 0; i<N; i++){
        for(int j=0; j<N-i-1; j++){
            if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
        }
    }

    // 出力
    for(int i = 0; i<N-1; i++){
        cout << arr[i] <<" ";
    }
    cout << arr[N-1] << endl;

    return 0;
}
