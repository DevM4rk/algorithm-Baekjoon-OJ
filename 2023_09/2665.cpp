#include <bits/stdc++.h>

using namespace std;

int n;
int board[51][51];
int vis[51][51];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        string s; cin >> s;
        for(int j=0; j<n; j++){
            board[i][j] = s[j]-'0';
        }
    }

    for(auto v : vis){
        fill(v, v+n, INT_MAX);
    }

    queue<pair<int,int>> q;
    q.push({0,0});
    vis[0][0] = 0;

    while(!q.empty()){
        auto [x,y] = q.front(); q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx <0 || nx >= n || ny <0 || ny >= n) continue;
            if(board[nx][ny] == 0 ){
                if( vis[nx][ny] > vis[x][y]+1){
                    vis[nx][ny] = vis[x][y]+1;
                    q.push({nx,ny});
                }
            }
            else{
                if( vis[nx][ny] > vis[x][y]){
                    vis[nx][ny] = vis[x][y];
                    q.push({nx,ny});
                }
            }
        }
    }

    cout << vis[n-1][n-1];
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout << vis[i][j];
    //     }
    //     cout << endl;
    // }
}