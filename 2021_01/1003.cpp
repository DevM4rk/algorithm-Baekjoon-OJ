#include <iostream>

using namespace std;

int T, N, arr[41][2]={0,};

void solve(){ 
    for( int i=2; i<=N; i++){
        arr[i][0] = arr[i-1][0] + arr[i-2][0];
        arr[i][1] = arr[i-1][1] + arr[i-2][1];
    }
    
    cout << arr[N][0] << " " << arr[N][1] << "\n";
}

/*
0  1 0
1  0 1
2  1 1      2
3  1 2      2 1
4  2 3      3 2  =  2 1 2
5  3 5      4 3  =  3 2 2 1 = 2 1 1 0 1 0 1 
6  5 8      5 4  =  4 3 3 2
*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    arr[0][0] = 1;
    arr[0][1] = 0;
    arr[1][0] = 0;
    arr[1][1] = 1;
        
    cin >> T;
    
    while(T--){
        cin >> N;

        solve();
    }
}
