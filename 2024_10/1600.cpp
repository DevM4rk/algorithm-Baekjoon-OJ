#include <bits/stdc++.h>

using namespace std;

int k,n,m,ans=INT_MAX;
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
int dx2[] = {-2,-1,1,2,2,1,-1,-2};
int dy2[] = {1,2,2,1,-1,-2,-2,-1};
int board[200][200];
int vis[200][200][31];

int main(){
    cin >> k >> m >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
        }
    }

    queue<pair<pair<int,int>,pair<int,int>>> q;
    q.push({{0,0},{1,0}});  //0이 방문x , 1이 방문o횟수0, 2부터 방문o횟수1
    vis[0][0][0]=1;

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        auto [x,y] = cur.first;
        auto [cnt,hrs] = cur.second;
        // cout << x << " " << y << " " << cnt << " " << hrs << endl;

        if(ans <= cnt) continue;
        if(x==n-1 && y==m-1){
            ans = min(ans, cnt-1);
            // cout << " min"<< ans << endl;
            continue;
        }


        if(hrs+1 <= k){
            for(int i=0; i<8; i++){
                int nx = x + dx2[i];
                int ny = y + dy2[i];
                if(nx<0|ny<0|nx>=n|ny>=m) continue;
                if(board[nx][ny]==1) continue;
                if(vis[nx][ny][hrs+1]>0 && vis[nx][ny][hrs] <= cnt+1) continue;

                // cout << "horse" << " " << nx << " " << ny << endl;

                vis[nx][ny][hrs+1] = cnt+1;
                q.push({{nx,ny},{cnt+1,hrs+1}});
            }
        }

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0|ny<0|nx>=n|ny>=m) continue;
            if(board[nx][ny]==1) continue;
            if(vis[nx][ny][hrs]>0 && vis[nx][ny][hrs] <= cnt+1) continue;

                // cout << "nomar" << " " << nx << " " << ny << endl;

            vis[nx][ny][hrs] = cnt+1;
            q.push({{nx,ny},{cnt+1,hrs}});
        }

    }
    if(ans == INT_MAX) ans = -1;
    cout << ans;
}