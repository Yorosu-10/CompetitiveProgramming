#include <iostream>

using namespace std;
 
int main(){
    int H, W, i, j;

    while(1){
        cin >> H >> W;
        
        if(H==0&&W==0) break;

        for(i=0;i<H;i++){
            for(j=0;j<W;j++){
                if(i%2==j%2){
                    cout << "#";
                }else{
                    cout << ".";
                }
            }
            cout << endl;
        }
        cout << endl;
    }
    
    return 0;
}