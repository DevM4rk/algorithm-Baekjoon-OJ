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

struct node{
    int x1,y1,x2,y2,cnt;
    node(int x1_, int y1_, int x2_, int y2_, int cnt_) : x1(x1_), y1(y1_), x2(x2_), y2(y2_), cnt(cnt_) {}
};

int n,m;
char arr[10][10];
queue<node> q;
map<pair<pii,pii>, int> vis;

const int dx[4] = {0,0,1,-1};
const int dy[4] = {1,-1,0,0};

void move(int &x, int &y, int &cnt, int i){
    while(arr[x][y] != 'O' && arr[x+dx[i]][y+dy[i]] != '#'){
        x += dx[i];
        y += dy[i];
        cnt++;
    }
}

void bfs(){
    while(!q.empty()){
        auto cur = q.front(); q.pop();

        //cout << cur.x1 << " " << cur.y1 << " " << cur.x2 << " " << cur.y2 << " " << cur.cnt << endl;

        if(cur.cnt >= 10) break;    // 예제 출력 7번 같은 경우, 둘이 동시에 빠지게 되면 큐가 비어서 출력후 return을 하게 되면 0이 출력이 되지 않음

        for(int i=0; i<4; ++i){
            int rx = cur.x1;
            int ry = cur.y1;
            int bx = cur.x2;
            int by = cur.y2;
            int cnt = cur.cnt+1;
            int rc=0, bc=0;

            move(rx,ry,rc,i);
            move(bx,by,bc,i);

            if(arr[bx][by] == 'O') continue;
            if(arr[rx][ry] == 'O'){
                cout << cnt;
                return;
            }

            if(rx == bx && ry == by){
                if(rc > bc) rx -= dx[i], ry -= dy[i];
                else bx -= dx[i], by -= dy[i];  
            }

            if(vis.count({{rx,ry},{bx,by}})) continue;
            vis[{{rx,ry},{bx,by}}]++;
            q.push(node(rx,ry,bx,by,cnt));
        }
    }
    cout << -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    int rx,ry,bx,by;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            cin >> arr[i][j];            
            if(arr[i][j] == 'R')
                rx = i, ry = j;
            else if(arr[i][j] == 'B')
                bx = i, by = j;
        }
    }

    vis[{{rx,ry},{bx,by}}]++;
    q.push(node(rx,ry,bx,by,0));

    bfs();
}