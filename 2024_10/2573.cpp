#include <bits/stdc++.h>

using namespace std;

int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

int n,m;
vector<vector<int>> vis(300, vector<int>(300, 0));
vector<vector<int>> board(300, vector<int>(300, 0));
vector<vector<int>> temp(300, vector<int>(300, 0));

void bfs(int a,int b){
    
    queue<pair<int,int>> q;
    q.push({a,b});
    vis[a][b] = 1;

    while(!q.empty()){
        auto [x,y] = q.front(); q.pop();

        int cnt=0;
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0||ny<0||nx>=n||ny>=m) continue;
            if(vis[nx][ny]) continue;
            if(board[nx][ny]==0){
                cnt++;
            }
            else{
                vis[nx][ny]=1;
                q.push({nx,ny});
            }
        }
        temp[x][y] = board[x][y]-cnt;
        if(temp[x][y] < 0 ) temp[x][y]=0;

    }
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
        }
    }

    
    int k,check;
    for(k=0;;k++){
        check=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 0 || vis[i][j]) continue;
                if(check) {
                    check++;
                    break;
                }
                bfs(i,j);
                check++;
            }
            if(check==2) break;
        }
        // cout << k << " " << check << endl;
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         cout << temp[i][j];
        //     }
        //     cout << endl;
        // }

        board = temp;
        temp = vector<vector<int>>(300, vector<int>(300, 0));
        vis = vector<vector<int>>(300, vector<int>(300, 0));
        if(check==2 || check==0) break;
    }

    if(check==0) k=0;
    cout<< k;

}
/*
처음입력부터 떨어져있는경우

*/