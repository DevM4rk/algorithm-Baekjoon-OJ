#include <iostream>

using namespace std;

int N, white = 0, blue = 0;
int arr[130][130]={0,};

void division(int x, int y, int size){
    int cnt = 0; // 0이면 all white, 최대값일 경우 all blue
    
    for(int i=x; i< x+size; i++)
        for(int j=y; j< y+size; j++)
            if(arr[i][j] == 1) cnt++;

    if(cnt == 0) white++;
    else if( cnt == size*size) blue++;
    else {
        division(x, y, size/2);
        division(x, y + size/2, size/2);
        division(x + size/2, y, size/2);
        division(x + size/2, y + size/2, size/2);
    }   
}

int main(){

    cin >> N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> arr[i][j];

    division(0,0,N);

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