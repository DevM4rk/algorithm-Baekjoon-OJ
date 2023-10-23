#include <bits/stdc++.h>

using namespace std;

int n,m,sx,ex,sy,ey,ans;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int board[300][300];
int vis[300][300];

void debug(){
    cout << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << board[i][j];
        }
        cout << endl;
    }
}

int main(){
    cin >> n >> m;
    cin >> sx >> sy >> ex >> ey;
    sx--; sy--; ex--; ey--;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char a; cin >> a;
            if(a == '#') a = '3';
            else if(a == '*') a = '0';
            board[i][j] = a - '0';
        }
    }

    bool check = false;
    while(!check){
        ans++;
        queue<pair<int,int>> q;
        q.push({sx,sy});
        vis[sx][sy] = 1;

        while(!q.empty()){
            auto [x,y] = q.front(); q.pop();

            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if(vis[nx][ny]) continue;

                vis[nx][ny] = 1;
                if(board[nx][ny] == 0){
                    q.push({nx,ny});
                } 
                else if(board[nx][ny] == 1){
                    board[nx][ny] = 0;
                }
                else if(board[nx][ny] == 3){
                    check = true;
                }
            }
            if(check) break;
        }

        for(auto v : vis) fill(v, v+m, 0);
    }



    cout << ans;
}