#include <bits/stdc++.h>

using namespace std;

vector<string> p;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int vis[5][5];
bool safe = true;

void dfs(int x, int y, int cnt){
    if(cnt == 2 || !safe) return;
    
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
        if(vis[nx][ny] || p[nx][ny] == 'X') continue;
        if(p[nx][ny] == 'P') safe = false; //³¡
        vis[nx][ny] = true;
        dfs(nx,ny,cnt+1);
    };
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(auto a : places){
        p=a;
        for(int i=0; i<5; i++){
            
            for(int k=0; k<5; k++) fill(vis[k], vis[k]+5, false);
            safe = true;
            for(int j=0; j<5; j++){
                //cout << a[i][j] ;
                if( a[i][j] != 'P') continue;
                cout << i << " " << j << endl;
                vis[i][j]= true;
                dfs(i,j,0);
                for(int k=0; k<5; k++) fill(vis[k], vis[k]+5, 0);

                if(!safe){
                    //cout << "IN" << endl;
                    answer.push_back(0);
                    break;
                }
            }
            if(!safe) break;
        }
        if(safe)answer.push_back(1);
    }
    
    return answer;
}