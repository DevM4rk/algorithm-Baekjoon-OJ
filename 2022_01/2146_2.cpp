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

int arr[101][101];
int dist[101][101];
int n, cnt;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
queue<pii> Q;

void BFS(int x, int y){
    queue<pii> Q;
    Q.push({x,y});
    arr[x][y] = cnt;
    
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int dir=0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(arr[nx][ny] == 1){
                arr[nx][ny] = cnt;
                Q.push({nx,ny});
            }
        }
    }
}

void Bridge(){
    int ans=99999;
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int dir=0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(arr[nx][ny] == arr[cur.X][cur.Y]) continue; // 같은 색일 경우 패스
            if(arr[nx][ny] != 0){       //다른 땅을 만난 경우
                //cout << nx << " " << ny << " " << dist[nx][ny] << " " << dist[cur.X][cur.Y] << endl;
                ans = min(ans, dist[nx][ny] + dist[cur.X][cur.Y]);    //cur와 (nx,ny) 각각 육지로부터 떨어진 거리를 합치는 작업
            }
            if(arr[nx][ny] == 0){        //바다인 경우 
                arr[nx][ny] = arr[cur.X][cur.Y];    // 섬의 영역 확장
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                Q.push({nx,ny});
            }
        }
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> arr[i][j];
    
    cnt=1;
    for(int i=0; i<n; i++){     //섬의 숫자를 2부터 부여힘
        for(int j=0; j<n; j++){
            if(arr[i][j] != 1) continue;
            cnt++;
            BFS(i,j);
        }
    }

    for(int i=0; i<n; i++)
        fill(dist[i], dist[i]+n, -1);

    // 큐에 섬을 다 넣음
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] == 0) continue;
            dist[i][j] = 0;
            Q.push({i,j});
        }
    }

    // 모든 섬을 BFS 돌려 섬의 영역을 확장하다가 껍데기끼리 겹치는 순간을 찾는 방식
    Bridge();
}