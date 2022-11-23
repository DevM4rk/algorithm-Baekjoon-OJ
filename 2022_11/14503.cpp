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
int r,c,k; 
int board[51][51];

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    cin >> r >> c >> k;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
        }
    }

    queue<tp> q;
    q.push({r,c,k});
    

    while(!q.empty()){
        auto [x,y,d] = q.front(); q.pop();

        if(board[x][y] == 0){
            board[x][y] = 2;
            ans++;    
        }

        bool pass = false;
        for(int i=1; i<=4; i++){
            int nd = d-i<0 ? d-i+4 : d-i;
            int nx = x + dx[nd];
            int ny = y + dy[nd];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(board[nx][ny] != 0) continue;
            if(pass) continue;
            
            q.push({nx,ny,nd});
            pass = true;
        }

        if(pass) continue;
        
        int nd = (d+2)%4;
        int nx = x + dx[nd];
        int ny = y + dy[nd];
        if(nx < 0 || ny < 0 || nx >= n || ny >= m) break;
        if(board[nx][ny] == 1) break;
        
        q.push({nx,ny,d});

    }

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout << board[i][j];
    //     }
    //     cout << endl;
    // }

    cout << ans;
}