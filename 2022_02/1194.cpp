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
int visit[1<<6][51][51]; // key�� 6��,  2^6������ ����� ��

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

struct node{
    int x,y,cnt,k;
    node(int x_, int y_, int cnt_, int k_){
        x = x_;
        y = y_;
        cnt = cnt_;
        k = k_;
    }
};

void bfs(){
    visit[0][sx][sy]=true;
    queue<node> q;
    q.push(node(sx,sy,0,0));

    while(!q.empty()){
        auto cur = q.front(); q.pop();

        //cout << cur.x << " " << cur.y << " " << cur.cnt << " " << cur.k << endl;

        if(board[cur.x][cur.y]=='1'){
            ans = cur.cnt;
            return;
        }

        for(int i=0; i<4; i++){
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[nx][ny]=='#') continue;
                    
            if(strchr("ABCDEF",board[nx][ny])){     // ��
                int hasKey = cur.k & (1 << board[nx][ny]-'A'); // �ش� Ű�� ���� �ִ����� �˾ƾ� �ϱ� ������ and ������, 1���� ���� ����
                if(hasKey && !visit[cur.k][nx][ny]){
                    visit[cur.k][nx][ny] = true;
                    q.push(node(nx, ny, cur.cnt+1, cur.k));  
                }
            }
            else if(strchr("abcdef",board[nx][ny])){     // ����
                int newKey = cur.k | (1 << board[nx][ny]-'a'); // ���踦 ��� ì�ܾ� �ϱ� ������ or ������, �������� ���� ����
                if(!visit[newKey][nx][ny]){
                    visit[newKey][nx][ny] = true;
                    q.push(node(nx, ny, cur.cnt+1, newKey));
                }
            }
            else{
                if(!visit[cur.k][nx][ny]){
                    visit[cur.k][nx][ny] = true;
                    q.push(node(nx, ny, cur.cnt+1, cur.k));
                }
            }
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

    bfs();

    if(ans==0) ans=-1;
    cout << ans;
}
/*
64  1
32  1
16  1
8   1
4   1
2   1
1   1
*/