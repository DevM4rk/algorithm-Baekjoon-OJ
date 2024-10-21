#include <bits/stdc++.h>

using namespace std;

int n;
int cnt=2;
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
vector<vector<int>> vis(100, vector<int>(100, 0));
vector<vector<int>> arr(100, vector<int>(100, 0));

void bfs(int a, int b){
    
    arr[a][b]=cnt;
    queue<pair<int,int>> q;
    q.push({a,b});

    while(!q.empty()){
        auto [x,y] = q.front(); q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx <0 || ny <0 || nx >= n || ny >= n) continue;
            if(arr[nx][ny] == cnt) continue;
            if(arr[nx][ny]==0) continue;
            arr[nx][ny] = cnt;
            q.push({nx,ny});
        }
    }

}

int main(){
    cin >> n;
    for(int i=0;i <n;i++)
        for(int j=0; j<n; j++)
            cin >> arr[i][j];

    for(int i=0;i <n;i++){
        for(int j=0; j<n; j++){
            if(arr[i][j]>1 || arr[i][j]==0) continue;
            bfs(i,j);
            cnt++;
        }
    }

    // for(int i=0;i <n;i++){
    //     for(int j=0; j<n; j++){
    //         cout << arr[i][j];
    //     }
    //     cout << endl;
    // }


    int ans=INT_MAX;
    queue<pair<int,int>> q;
    
    for(int i=0;i <n;i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] != 0)
                q.push({i,j});
        }
    }
    
    while(!q.empty()){
        auto [x,y] = q.front(); q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx <0 || ny <0 || nx >= n || ny >= n) continue;
            if(arr[nx][ny] == arr[x][y]) continue;
            if(vis[nx][ny] > 0){
                if(arr[nx][ny] != 0){
                    
                    ans = min(ans, vis[nx][ny]+vis[x][y]);
                    continue;
                }
            }
// cout << nx << " " << ny << " " << x << " " << y << endl;
                                    
//                     for(int i=0;i <n;i++){
//                         for(int j=0; j<n; j++){
//                             cout << vis[i][j];
//                         }
//                         cout << endl;
//                     }

            vis[nx][ny] = vis[x][y]+1;
            arr[nx][ny] = arr[x][y];
            q.push({nx,ny});
        }
    }

    cout << ans;

}