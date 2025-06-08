#include <bits/stdc++.h>

#define endl "\n"
#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef tuple<int,int,int> tp;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector <ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

int n,m,ans=INT_MAX;
int board[50][50];
vector<pair<int,int>> vrs;
vector<int> vis_vrs;

int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

void bfs(){
    vector<vector<int>> vis(50, vector<int>(50, 0));
    queue<pair<int,int>> q;

    //if(ans == 4) return;
    for(auto i : vis_vrs) {
        if(i>0){
            auto [x,y] = vrs[i-1];
            q.push({x,y});
            vis[x][y]=1;
            // cout << x << y << " ";
        }
    }
    // cout << endl;

    while(!q.empty()){
        auto [x,y] = q.front(); q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(vis[nx][ny]) continue;
            if(board[nx][ny]==1) continue;
            if(board[nx][ny]==2){
                vis[nx][ny] = vis[x][y];                
            }
            else{
                vis[nx][ny] = vis[x][y] + 1;
            }
            q.push({nx,ny});
        }
    }
    
    int c=-2;
    bool b=false;
    for(int i=0; i<n; i++){
        if(b) {
            c=-2;
            break;
        }
        for(int j=0; j<n; j++){
            if(vis[i][j]==0 && board[i][j]!=1) b = true;
            c = max(c,vis[i][j]-1);
        }
    }

    if(b && ans==INT_MAX) ans = -1;

    if(c>=0) {
        if(ans == -1) ans = INT_MAX;
        ans = min(ans, c);
    }
    if(c != 3) return;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << vis[i][j] << " ";
        }
        cout << endl;
    }
    cout << ans << endl;
    cout << endl;
}

void pick(int cnt){
    if(cnt == m){
        bfs();
        // for(auto a : vis_vrs) cout << a << " " ;
        // cout << endl;
        return;
    }

    for(int i=0; i<vrs.size(); i++){
        if(vis_vrs[i]) continue; //해야되나 vis체크
        vis_vrs[i] = i+1;
        pick(cnt+1);
        vis_vrs[i] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
            if(board[i][j]==2) vrs.push_back({i,j});
        }
    }
    vis_vrs = vector<int> (vrs.size(), 0);

    pick(0);

    cout << ans;
}
/*
8:09~
7 1
0 0 0 1 1 1 1
2 1 0 1 1 1 1
2 1 0 1 1 1 1
2 1 0 1 1 1 1
0 1 0 1 1 1 1
2 1 0 1 1 1 1
0 0 0 1 1 1 1
*/