#include <iostream>
#include <string>

using namespace std;

int main(){
    int n, j;
    cin>>n;

    string taro, hanako;

    int tp, hp = 0;

    for(int i=0; i<n; i++){
        cin>>taro>>hanako;

        if((int)taro.size() > (int)hanako.size()){
            for(j=0;j<(int)hanako.size();j++){
                if(taro[j]>hanako[j]){
                    tp=tp+3;
                    break;
                }else if(taro[j]<hanako[j]){
                    hp=hp+3;
                    break;
                }else if(taro[j]=hanako[j]){
                }
            }
            if(j==(int)hanako.size()){
                tp=tp+3;
            }
        }
        else if((int)taro.size() < (int)hanako.size()){
            for(j=0;j<(int)taro.size();j++){
                if(taro[j]>hanako[j]){
                    tp=tp+3;
                    break;
                }else if(taro[j]<hanako[j]){
                    hp=hp+3;
                    break;
                }else if(taro[j]=hanako[j]){
                }
            }
            if(j==(int)taro.size()){
                hp=hp+3;
            }
        }
        else if((int)taro.size() == (int)hanako.size()){
            for(j=0;j<(int)taro.size();j++){
                if(taro[j]>hanako[j]){
                    tp=tp+3;
                    break;
                }else if(taro[j]<hanako[j]){
                    hp=hp+3;
                    break;
                }else if(taro[j]=hanako[j]){
                }
            }
            if(j==(int)taro.size()){
                hp=hp+1;
                tp=tp+1;
            }
        }
    }

    cout << tp << " " << hp << endl;

    return 0;

}