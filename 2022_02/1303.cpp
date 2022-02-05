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

int n,m,ans1,ans2;
char arr[101][101];
bool visit[101][101];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void bfs(char color, int a, int b){
    visit[a][b] = true;
    queue<pii> q;
    q.push({a,b});

    int cnt=1;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        int x = cur.first;
        int y = cur.second;

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(visit[nx][ny] || arr[nx][ny] != color) continue;

            cnt++;
            visit[nx][ny] = true;
            q.push({nx,ny});
        }
    }

    if(color == 'W') ans1 += cnt*cnt;
    else ans2 += cnt*cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> m >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> arr[i][j];

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(!visit[i][j]) bfs(arr[i][j],i,j);
    

    cout << ans1 << " " << ans2;
}
//11:10 ~ 20