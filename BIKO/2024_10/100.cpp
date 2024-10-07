#include <bits/stdc++.h>

using namespace std;

int dx[] ={0,0,1,-1, -1,-1,1,1}; // 0~3직선 4~7대각
int dy[] ={-1,1,0,0, -1,1,-1,1};

int n,m,ans;
int board[50][50];

int dfs(int x, int y, int dir){
    int sum = board[x][y];

    if(dir == 1){
        for(int i=0; i<4; i++){
            int nx=x;
            int ny=y;
            for(int j=0; j<m; j++){
                nx +=dx[i];
                ny +=dy[i];
                if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                sum += board[nx][ny];
            }
        }
    }
    else{
        for(int i=4; i<8; i++){
            int nx=x;
            int ny=y;
            for(int j=0; j<m; j++){
                nx +=dx[i];
                ny +=dy[i];
                if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                sum += board[nx][ny];
            }
        }
    }

    return sum;
}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){            
            ans = max(ans, dfs(i,j,1)); //직선

            ans = max(ans, dfs(i,j,2)); //대각
        }
    }

    cout << ans;
}
/*
설계
    
    중앙 더하기
    그냥 이중포문
    for(방향 ) if 1이면 0~3 2면 4~7
        for(j=1길이 m) 
            if(범위밖안나가게)
    

*/