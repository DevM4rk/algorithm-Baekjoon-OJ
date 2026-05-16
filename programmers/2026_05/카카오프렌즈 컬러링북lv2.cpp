#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};


vector<int> solution(int m, int n, vector<vector<int>> picture) {
    
    vector<int> answer(2, 0);
    
    int vis[101][101] = {0,};
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(vis[i][j] == 1 || picture[i][j] == 0) continue;
            answer[0]++;
            vis[i][j] = 1;
            int p = picture[i][j];
            int cnt=1;
            
            queue<pair<int,int>> q;
            q.push({i,j});
            
            while(!q.empty()){
                auto [x,y] = q.front(); q.pop();
                
                for(int k=0; k<4; k++){
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(vis[nx][ny] == 1 || picture[nx][ny] != p) continue;
                    vis[nx][ny] = 1;
                    cnt++;
                    q.push({nx,ny});
                }
            }
            
            answer[1] = max(answer[1], cnt);
            
        }
    }
    
    return answer;
}
/*
3:33
1 1 1 0
1 2 2 0
1 0 0 1
0 0 0 1
0 0 0 3
0 0 0 3

1 1 1 0
1 1 1 0
0 0 0 1
0 0 0 1
0 0 0 1
0 0 0 1
*/