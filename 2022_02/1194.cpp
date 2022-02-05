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

int n,m,sx,sy,ans;
string board[51];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

struct node{
    int x,y,cnt,k;
    vector<bool> key;
    vector<vector<bool>> v;
    node(int x_, int y_, int cnt_, vector<bool> &key_, vector<vector<bool>> &v_, int k_){
        x = x_;
        y = y_;
        cnt = cnt_;
        key = key_;
        v = v_;
        k = k_;

        if(k!=9){
            key[k] = true;
            for(int i=0; i<n; i++)
                for(int j=0; j<m; j++)
                    v[i][j] = false;
        }
        v[x][y] = true;
    }
};

void bfs(node nod){
    nod.v[sx][sy]=true;
    queue<node> q;
    q.push(nod);

    while(!q.empty()){
        auto cur = q.front(); q.pop();

        //cout << cur.x << " " << cur.y << " " << cur.cnt << " " << cur.k << endl;

        for(int i=0; i<4; i++){
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(cur.v[nx][ny] || board[nx][ny]=='#') continue;
            if(strchr("ABCDEF",board[nx][ny])) if(!cur.key[board[nx][ny]-'A']) continue; //문인데 키가 없다면 패스
            if(board[nx][ny]=='1'){
                ans = cur.cnt+1;
                return;
            }
            
            int k=9;
            if(strchr("abcdef",board[nx][ny])){
                if(cur.key[board[nx][ny]-'a']) continue;    //이미 방문한 곳이라면
                else k = board[nx][ny]-'a';
            }

            q.push(node(nx, ny, cur.cnt+1, cur.key, cur.v, k));
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> board[i];
        
        for(int j=0; j<m; j++){
            if(board[i][j]=='0'){
                sx = i;
                sy = j;
            }
        }
    }

    vector<vector<bool>> visit(n, vector<bool> (m, 0));
    vector<bool> k(6,false);

    bfs(node(sx,sy,0,k,visit,9));

    if(ans==0) ans=-1;
    cout << ans;
}