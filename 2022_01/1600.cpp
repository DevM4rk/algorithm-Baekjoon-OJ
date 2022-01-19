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

const int Max = 201;

int arr[Max][Max];
int vis[31][Max][Max];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int dhx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};   // horse moving
int dhy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int k,n,m;

void BFS(int cnt, int x, int y){
    queue<tp> q;
    q.push({cnt,x,y});

    while(!q.empty()){
        int cc, cx, cy;     //current
        tie(cc, cx, cy) = q.front(); q.pop();
        
        //horse move
        if(cc < k){
            for(int i=0; i<8; i++){
                int nc = cc + 1;
                int nx = cx + dhx[i];
                int ny = cy + dhy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(arr[nx][ny] || vis[nc][nx][ny]) continue;
                vis[nc][nx][ny] = vis[cc][cx][cy] + 1;
                q.push({nc, nx, ny});
            }
        }

        //basic move
        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(arr[nx][ny] || vis[cc][nx][ny]) continue;
            vis[cc][nx][ny] = vis[cc][cx][cy] + 1;
            q.push({cc, nx, ny});            
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> k >> m >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> arr[i][j];

    BFS(0,0,0);

    int ans = 99999;
    for(int i=0; i<=k; i++)
        if(vis[i][n-1][m-1] != 0)
            ans = min(ans, vis[i][n-1][m-1]);

    if(ans == 99999) ans = -1;
    if(n==1 && m==1) ans = 0;   //1 1 1 0 대입 시 -1이 출력되는 반례
    cout << ans;
}