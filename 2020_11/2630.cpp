#include <iostream>

using namespace std;

int N, white = 0, blue = 0;
int arr[130][130]={0,};

void division(int xs, int ys, int xe, int ye){
    int cnt = 0; // 0이면 all white, 최대값일 경우 all blue
    
    for(int i=xs; i<xe; i++)
        for(int j=ys; j<ye; j++)
            if(arr[i][j] == 1) cnt++;

    if(cnt == 0) white++;
    else if( cnt == (xe-xs)*(ye-ys)) blue++;
    else {
        division(xs, ys, (xs+xe)/2, (ys+ye)/2);
        division((xs+xe)/2, ys, xe, (ys+ye)/2);
        division(xs, (ys+ye)/2, (xs+xe)/2, ye);
        division((xs+xe)/2, (ys+ye)/2, xe, ye);
    }   
}

int main(){

    cin >> N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> arr[i][j];

    division(0,0,N,N);

    cout << white << endl;  // 0
    cout << blue << endl;   // 1
}

// ((1000)(0110)((1001)001)1)
/* 
모두 같은 숫자이면 그대로 진행, blue인지 white인지 카운트
하나라도 다를경우 
N/2를 해서 재귀


8
1 1 0 0 0 0 1 1
1 1 0 0 0 0 1 1
0 0 0 0 1 1 0 0
0 0 0 0 1 1 0 0
1 0 0 0 1 1 1 1
0 1 0 0 1 1 1 1
0 0 1 1 1 1 1 1
0 0 1 1 1 1 1 1
*/