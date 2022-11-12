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

int n,m,ans;
vector<vi> board(8, vi(8,0));
vpii virus;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void bfs(){

    vector<vi> cp_board = board;
    queue<pii> q;
    for(auto v : virus) q.push(v);

    while(!q.empty()){
        auto [x,y] = q.front(); q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(cp_board[nx][ny]) continue;

            cp_board[nx][ny] = 2;
            q.push({nx,ny});
        }
    }

    int cnt=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(cp_board[i][j]) continue;
            cnt++;
        }
    }
    
    ans = max(ans, cnt);
}

void dfs(int cnt){
    if(cnt == 3){
        bfs();
        return;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j]) continue;
            board[i][j] = 1;
            dfs(cnt+1);
            board[i][j] = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
            if(board[i][j]==2) virus.push_back({i,j});
        }
    }

    dfs(0);

    cout << ans;
}