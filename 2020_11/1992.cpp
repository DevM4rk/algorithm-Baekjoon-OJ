#include <iostream>

using namespace std;

int N;
char arr[65][65]={0,};

void division(int xs, int ys, int xe, int ye){
    int cnt_zero = 0;
    int cnt_one = 0;
    
    for(int i=xs; i<xe; i++){
        for(int j=ys; j<ye; j++){
            if(arr[i][j] == '0') cnt_zero++;
            else if(arr[i][j] == '1') cnt_one++;
        }
    }
    
    if(cnt_zero !=0 && cnt_one != 0){
        cout << "(";
        division(xs, ys, (xs+xe)/2, (ys+ye)/2);
        division(xs, (ys+ye)/2, (xs+xe)/2, ye);
        division((xs+xe)/2, ys, xe, (ys+ye)/2);
        division((xs+xe)/2, (ys+ye)/2, xe, ye);
        cout << ")";
    }
    
    else if(cnt_zero == 0) cout << "1";
    else cout << "0";

}

int main(){

    cin >> N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> arr[i][j];

    division(0,0,N,N);
}
