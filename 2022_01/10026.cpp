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

char board[101][101];
bool vis[101][101];
int n;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void BFS(int x, int y){
    queue<pii> Q;
    Q.push({x,y});
    vis[x][y] = true;

    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int i=0; i<4; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(board[x][y] != board[nx][ny] || vis[nx][ny]) continue;
            vis[nx][ny] = true;
            Q.push({nx,ny});
        }
    }
}

int area(){
    int cnt=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(vis[i][j]) continue;
            cnt++;
            BFS(i,j);
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> board[i][j];

    //notRG
    int notRG = area();

    //√ ±‚»≠
    for(int i=0; i<n; i++)
        fill(vis[i], vis[i]+n, false);

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(board[i][j] == 'R')
                board[i][j] = 'G';

    //isRG
    int isRG = area();
    cout << notRG << " " << isRG;

}