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

int Bridge(int x, int y){
    queue<pii> Q;
    Q.push({x,y});
    int color = arr[x][y];

    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int dir=0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(arr[nx][ny] == color || dist[nx][ny] >= 1) continue; // ���� ���� ���, ������ üũ�� �ٴ��� ��� �н�
            if(arr[nx][ny] != 0){       //�ٸ� ���� ���� ���
                //cout << nx << " " << ny << " " << cnt << endl;
                return dist[cur.X][cur.Y];
            }
            if(arr[nx][ny] == 0){        //�ٴ��� ��� 
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                Q.push({nx,ny});
            }
        }
    }
    return 99999;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> arr[i][j];
    
    cnt=1;
    for(int i=0; i<n; i++){     //���� ���ڸ� 2���� �ο���
        for(int j=0; j<n; j++){
            if(arr[i][j] != 1) continue;
            cnt++;
            BFS(i,j);
        }
    }

    int d = 99999;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] == 0) continue;
            d = min(d, Bridge(i,j));

            for(int i = 0; i < n; i++)
                fill(dist[i], dist[i] + n, 0);
        }
    }

    cout << d;
}