#include <bits/stdc++.h>

#define endl "\n"
#define all(v) v.begin(), v.end()

#define INF 987654321

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

int dx[4] = {1,-1,0,0}; //하상우좌
int dy[4] = {0,0,1,-1}; // 3k = 0,1,2,3
                        // 3k+1 = 0,1
                        // 3k+2 = 2,3

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n,m; cin >> n >> m;
    int sx,sy,ex,ey; cin >> sx >> sy >> ex >> ey;
    sx--; sy--; ex--; ey--;

    vector<vi> v(n, vi(m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> v[i][j];

    vector<vector<vi>> d(n, vector<vi>(m, vi(3, INF))); // 수정필요

    priority_queue<pair<pii,pii>, vector<pair<pii,pii>>, greater<>> pq;//(가중치,횟수)(x,y)
    d[sx][sy][0]=0;
    pq.push({{0,0}, {sx,sy}});

    while(!pq.empty()){
        int dist = pq.top().first.first;
        int k = pq.top().first.second;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        if(d[x][y][k] != dist) continue;

        k++;
        k %= 3;
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if((k==1 && i==2) || (k==1 && i==3))
                continue;
            else if((k==2 && i==0) || (k==2 && i==1))
                continue;

            if(nx < 0 || ny < 0 ||  nx >= n || ny >= m || v[nx][ny] == -1) continue;
        
            if(d[nx][ny][k] > dist + v[nx][ny]){
                d[nx][ny][k] = dist + v[nx][ny];
                pq.push({{d[nx][ny][k],k}, {nx,ny}});
            }
        }
    }

    int ans = INF;
    for(int i=0; i<3; i++)
        ans = min(ans, d[ex][ey][i]);
    
    if(ans == INF) ans = -1;
    cout << ans;
}