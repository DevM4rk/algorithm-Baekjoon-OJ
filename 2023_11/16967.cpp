#include <bits/stdc++.h>

using namespace std;

int board[601][601];

int main(){
    int n,m, x,y; cin >> n>>m>>x>>y;
    for(int i=0; i<n+x; i++){
        for(int j=0; j<m+y; j++){
            cin >> board[i][j];
        }
    }

    for(int i=x; i<n; i++){
        for(int j=y; j<m; j++){
            board[i][j] -= board[i-x][j-y];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

/*
3 3 1 1
1 2 3 0
4 6 8 3
7 12 14 6
0 7 8 9

x,y 값이 1보다 커야하기 때문에 첫번째 행과 (1,0)은
무조건 알 수 있음
1 2 3

이걸 통해서 (x,y)위치부터 뺌


4 4 1 1

1 1 1 1 0
1 2 2 2 1
1 2 2 2 1
1 2 2 2 1
0 1 1 1 1
*/