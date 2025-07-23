#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

int solution(vector<string> storage, vector<string> requests) {
    
    int n = storage.size();
    int m = storage[0].size();
    int answer = n*m;
    
    vector<vector<int>> vis(n, vector<int>(m, 0));
    //√ ±‚»≠ vis = vector<vector<int>> (n, vector<int>(m, 0));
    
    
    for(auto in : requests){
        if ( in.size() == 1){
            queue<pair<int,int>> q;
            
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if((i!=0 && i!=n-1) && (j!=0 && j!=m-1)) continue;
                    
                    if(storage[i][j] == '9'){
                        q.push({i,j});
                        vis[i][j] = 1;
                    }
                    if(storage[i][j] == in[0]){
                        storage[i][j] = '9';
                        vis[i][j] = 1;
                        answer--;
                    }
                }
            }
            
            while(!q.empty()){
                auto [x,y] = q.front(); q.pop();
                
                for(int i=0; i<4; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if( nx >= n || ny >=m || nx<0 || ny<0) continue;
                    
                    if(vis[nx][ny]) continue;
                    vis[nx][ny] = 1;
                    
                    if(storage[nx][ny] == '9'){
                        q.push({nx,ny});
                    }
                    
                    if(storage[nx][ny] == in[0]){
                        storage[nx][ny] = '9';  
                        answer--;
                    }
                    
                }
            }
        
        
            vis = vector<vector<int>> (n, vector<int>(m, 0));
        }
        
        else{
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(storage[i][j] == in[0]){
                        storage[i][j] = '9';
                        answer--;
                    }
                }
            }
        }
    }
    
    // for(int i=0; i<n; i++){
    //     cout << storage[i] << endl;
    // }
    
    return answer;
}