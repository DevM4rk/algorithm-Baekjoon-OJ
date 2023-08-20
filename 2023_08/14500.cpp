#include <bits/stdc++.h>

using namespace std;

int n,m; 
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

int board[501][501];
int check[501][501];
int answer=0;

void dfs(int x, int y, int sum, int cnt){
    if(cnt == 3){
        // cout << x << y << sum << cnt  << answer << endl;
        answer = max(answer, sum);
        return ;
    }

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if( nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if( check[nx][ny] == true) continue;
        check[nx][ny] = true;
        dfs(nx,ny,sum+board[nx][ny],cnt+1);
        check[nx][ny] = false;

        //ㅗ모양 체크
        int nnx = nx + dx[i];
        int nny = ny + dy[i];
        if( nnx < 0 || nny < 0 || nnx >= n || nny >= m) continue;

        int sum = board[x][y] + board[nx][ny] + board[nnx][nny];

        int cx, cy;
        if(i<2){
            cx = nx + dx[2];
            if(cx >= 0 && cx < n) answer = max(answer, sum+board[cx][ny]);
            
            cx = nx + dx[3];
            if(cx >= 0 && cx < n) answer = max(answer, sum+board[cx][ny]);

        }
        else{
            cy = ny + dy[0];
            if(cy >= 0 && cy < m) answer = max(answer, sum+board[nx][cy]);

            cy = ny + dy[1];
            if(cy >= 0 && cy < m) answer = max(answer, sum+board[nx][cy]);

        }
    }
}

int main(){
    
    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            check[i][j] = true;
            dfs(i,j,board[i][j],0);
            check[i][j] = false;
        }
    }
    
    cout << answer;
}