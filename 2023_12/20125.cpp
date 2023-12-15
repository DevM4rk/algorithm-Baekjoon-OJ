#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> v(1000, vector<char>(1000));
int n,ex,ey;
int vis[1000][1000];
vector<int> body;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void bfs(int a, int b){

    queue<tuple<int,int,int>> q;
    q.push({a,b,1});
    vis[a][b] = 1;
    int sum = 0;

    while(!q.empty()){
        auto [x,y,cnt] = q.front(); q.pop();
        sum = cnt;
        vis[x][y] = 1;
            
        int check = 0;
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(v[nx][ny] == '*') check++;

            if(vis[nx][ny] || v[nx][ny] != '*') continue;
            //cout << nx << ny << endl;
            q.push({nx,ny,cnt+1});
        }

        if(check == 4){
            ex= x+1; ey = y+1;
            v[x][y] = '_';
            return; 
        }
    }

    body.push_back(sum);
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> v[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(v[i][j] == '*' && !vis[i][j]){
                // cout << i << j << endl;
                bfs(i,j);
            }
        }
    }

    cout << ex << " " << ey << endl;
    for(auto b : body)
        cout << b << " ";

}