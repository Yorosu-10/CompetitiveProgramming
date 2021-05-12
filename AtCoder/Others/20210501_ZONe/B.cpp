#include <iostream>
#include<iomanip>

using namespace std;

int main(){
    int N, D, H;
    int d, h;

    cin >> N >> D >> H;

    // 各d, hの直線のy切片のうち最大値が答え
    double y0[N]; //y切片
    double y0_max=0.0;

    for(int i=0; i<N; i++){
        cin >> d >> h;
        y0[i]=(double)H - (double)D*(H-h)/(D-d);
    }

    for(int i=0; i<N; i++){
        if(y0[i]>y0_max) y0_max = y0[i];
    }

    if(y0_max==0.0){
        cout << "0.0" << endl;
    }else{
        //整数部あわせて16桁
        cout << setprecision(16);
        cout << y0_max << endl;
    }

    return 0;
}