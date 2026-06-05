#include <bits/stdc++.h>

using namespace std;

int vis[501][501];
int oil[501][501];
int n,m,answer;

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

int solution(vector<vector<int>> land) {
    answer = 0;
    n = land.size();
    m = land[0].size();
    int type=0;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if( vis[i][j] >= 1 || land[i][j] == 0) continue;
            type++;
            vis[i][j] = type;
            
            int cnt=1;
            stack<pair<int,int>> st;
            st.push({i,j});
            queue<pair<int,int>> q;
            q.push({i,j});
            
            while(!q.empty()){
                auto [x,y] = q.front(); q.pop();
                for(int k=0; k<4; ++k){
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if(nx >= n || ny >= m || nx<0 || ny <0) continue;
                    if(vis[nx][ny] >= 1 || land[nx][ny] != 1) continue;
                    cnt++;
                    vis[nx][ny] = type;
                    st.push({nx,ny});
                    q.push({nx,ny});
                }
            }
            
            while(!st.empty()){
                auto [x,y] = st.top(); st.pop();
                oil[x][y] = cnt;
            }
        }
    }
    
    for(int j=0; j<m; j++){
        int sum=0;
        set<int> s;
        
        for(int i=0; i<n; i++){
            if(land[i][j] == 0) continue;
            
            if(s.find(vis[i][j]) == s.end()){
                s.insert(vis[i][j]);
                sum += oil[i][j];
            }
            
        }
        answer = max(answer, sum);
    }
  
    
    return answer;
}
/*
12:40 ~ 

한 줄에 똑같은 숫자가 8이 있을경우,, 문제네
*/