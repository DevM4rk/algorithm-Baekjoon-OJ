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

int n,m;
int arr[51][51];
queue<pair<pii,pii>> q; // x,y,color,cnt

int dx[8] = {-1,-1,-1,0,1,1,1,0};
int dy[8] = {-1,0,1,1,1,0,-1,-1};

void bfs(){

    int x,y,color,cnt;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        x = cur.X.X;
        y = cur.X.Y;
        color = cur.Y.X;
        cnt = cur.Y.Y;
        
        //cout << x << " " << y << " " << color << " " << cnt << endl;

        for(int i=0; i<8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(arr[nx][ny] == color || arr[nx][ny] != 0) continue;
            arr[nx][ny] = color;
            q.push({{nx,ny},{color,cnt+1}});
        }
    }
    cout << cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    int c=1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int a; cin >> a;
            if(a==1){
                arr[i][j]=c;
                q.push({{i,j},{c,0}});
                c++;
            }
        }
    }

    bfs();
}
//32~50