#include <iostream>

using namespace std;
 
int main(){
    int H, W, i, j;

    while(1){
        cin >> H >> W;
        
        if(H==0&&W==0) break;

        for(i=0;i<H;i++){
            if(i==0||i==H-1){
                for(j=0;j<W;j++){
                    cout << "#";
                }
            }
            else{
                for(j=0;j<W;j++){
                    if(j==0||j==W-1){
                        cout << "#";
                    }else{
                        cout << ".";
                    }
                }
            }
            cout << endl;
        }
        cout << endl;
    }
    
    return 0;
}