#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int mark_to_num(char mark){
    if(mark=='S') return 0;
    else if(mark=='H') return 1;
    else if(mark=='C') return 2;
    else if(mark=='D') return 3;
}

char num_to_mark(int num){
    if(num==0) return 'S';
    else if(num==1) return 'H';
    else if(num==2) return 'C';
    else if(num==3) return 'D';
}

int main(){
    int n, num;

    char mark;

    cin >> n;


    //スペースが必要
    vector< vector<bool> > card(4, vector<bool>(13));

    for(int i=0; i<4; i++){
        for(int j=0; j<13; j++){
            card[i][j]=0;
        }
    }

    for(int i=0; i<n; i++){
        cin >> mark >> num;
        card[mark_to_num(mark)][num-1] = 1;
    }
    for(int i=0; i<4; i++){
        for(int j=0; j<13; j++){
            if(card[i][j]==0) cout << num_to_mark(i) << " " << j+1 << endl;
        }
    }

    return 0;

}
