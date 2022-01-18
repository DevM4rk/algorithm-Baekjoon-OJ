#include <bits/stdc++.h>

#define endl "\n"
#define all(v) v.begin(), v.end()

#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef tuple<int,int,int> tp;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector <ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef unordered_map<int, int> mpii;

int ice[301][301];
bool vis[301][301];
int n,m ,year;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void init(){
    for(int i=0; i<n; i++)
        fill(vis[i], vis[i]+m, false);
}

void melt(){
    int arr[301][301] = {0};
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(ice[i][j] == 0) continue;
            for(int dir=0; dir<4; i++){
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(ice[nx][ny] == 0) arr[i][j]++;
            }
        }
    }
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            ice[i][j] = max(0, ice[i][j] - arr[i][j]);
}

void BFS(int x, int y){
    queue<pii> Q;
    Q.push({x,y});
    vis[x][y] = true;
    
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int dir=0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(ice[nx][ny] == 0 || vis[nx][ny]) continue;
            vis[nx][ny] = true;
            Q.push({nx,ny});
        }
    }
}

int area(){
    int cnt=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(ice[i][j] == 0 || vis[i][j]) continue;
            BFS(i,j);
            cnt++;
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> ice[i][j];
    
    while(true){
        year++;
        init();
        melt();

        int check = area();
        if(check>=2){
            cout << year;
            return 0;
        }
        else if(check==0){
            cout << 0;
            return 0;
        }
    }
}
//빙산 녹일 때 바로 0 만들어 버리면 옆의 빙산이 영향을 받음 
