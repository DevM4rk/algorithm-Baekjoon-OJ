#include <bits/stdc++.h>

#define endl "\n"
#define all(v) v.begin(), v.end()

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

int n,m,k,sx,sy,ex,ey;
char arr[1001][1001];
int visit[1001][1001];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int bfs(){
    visit[sx][sy]=1;
    queue<tp> q;
    q.push({sx,sy,1});  //x,y,cnt

    while(!q.empty()){
        int x,y,cnt;
        tie(x,y,cnt) = q.front(); q.pop();

        // cout << x << " " << y << " "  << cnt << endl;
        
        for(int i=0; i<4; i++){
            for(int j=1; j<=k; j++){
                int nx = x + dx[i]*j;
                int ny = y + dy[i]*j;
                // cout << nx << " " << ny << endl;
                if(nx == ex && ny == ey) return cnt;
                if(nx <= 0 || nx > n || ny <= 0 || ny > m) break;
                if(arr[nx][ny] == '#') break;

                if(visit[nx][ny]==0){       //새로운 곳이라면 방문하면서 체크
                    visit[nx][ny]=cnt+1;
                    q.push({nx,ny,cnt+1});
                }
                else if(visit[nx][ny] == cnt+1){    //이미 갔던곳이지만 숫자가 같을 경우 그 다음 건너편의 것들도 확인해야함 ,최신화
                    continue;
                }
                else if(visit[nx][ny] < cnt+1){ //진행 방향에 숫자가 적은게 있을 경우 이미 그 방향은 최신화되어있음
                    break;
                }
            }
            
            // for(int i=1; i<=n; i++){
            //     for(int j=1; j<=m; j++){
            //         cout << visit[i][j] << " ";
            //     }
            //     cout << endl;
            // }
            // cout << endl;

        }
    }

    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m >> k;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin >> arr[i][j];
    cin >> sx >> sy >> ex >> ey;

    cout << bfs();
}
/*
5 6 6
......
..#..#
......
....#.
......
1 1 3 6
*/