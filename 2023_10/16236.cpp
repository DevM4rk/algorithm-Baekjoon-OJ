#include <bits/stdc++.h>

using namespace std;

int n,ans;
int board[20][20];
int vis[20][20];
pair<int,int> srk_loc, srk_size;

int dx[] = {-1,0,0,1};
int dy[] = {0,-1,1,0};

void dfs(int a, int b){
    
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout << board[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << srk_size.first << " " << ans << endl;

    queue<tuple<int,int,int>> q;
    q.push({a,b,0});
    vis[a][b] = true;
    bool get = false;
    map<int,vector<int>> m;
    int check = 0;

    while(!q.empty()){
        auto [x,y,cnt] = q.front(); q.pop();

        if(check != cnt){
            check++;

            if(!m.empty()){
                for(auto v : m){
                    int sx = v.first;
                    int sy = v.second[0];
                    
                    board[sx][sy] = 0;

                    ans += check;

                    srk_loc = {sx,sy};
                    
                    auto [size, eat] = srk_size;
                    eat++;
                    if(size == eat) {
                        size++;
                        eat=0;
                    }
                    srk_size = {size,eat};
                    
                    for(auto v : vis) fill(v, v+n, 0);
                    break;
                }

                get = true;
                m.clear();
                break;
            }
        }
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(vis[nx][ny]) continue;
            if(board[nx][ny] > srk_size.first) continue;
            
            else if(board[nx][ny] != 0 && board[nx][ny] < srk_size.first){
                vis[nx][ny] = true;
                m[nx].push_back(ny);
                q.push({0,0,cnt+1});
            }

            else{ // == or 0
                vis[nx][ny] = true;
                q.push({nx,ny,cnt+1});
            }
        }

    }

    if(get) dfs(srk_loc.first, srk_loc.second);
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];

            if(board[i][j] == 9){
                board[i][j] = 0;
                srk_loc = {i,j};
                srk_size = {2,0};
            }
        }
    }
    
    dfs(srk_loc.first, srk_loc.second);

    cout << ans;
}