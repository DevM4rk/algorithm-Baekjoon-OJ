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

string board[1001];
int dist1[1001][1001];
int dist2[1001][1001];
int t,w,h;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> t;
    while(t--){
        cin >> w >> h;  // n = h , m = w
        
        //�ʱ�ȭ
        for(int i = 0; i < h; i++){
            fill(dist1[i], dist1[i]+w, -1);
            fill(dist2[i], dist2[i]+w, -1);
            board[i].clear();  
        }
        bool escape = false;

        for(int i = 0; i < h; i++)
            cin >> board[i];  

        queue<pair<int,int>> Q1 = {}, Q2 = {};

        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(board[i][j] == '*'){
                    Q1.push({i,j});
                    dist1[i][j] = 0;        
                }
                if(board[i][j] == '@'){
                    Q2.push({i,j});
                    dist2[i][j] = 0;
                }
            }
        }

        // �ҿ� ���� BFS
        while(!Q1.empty()){
            auto cur = Q1.front(); Q1.pop();
            for(int dir = 0; dir < 4; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if(dist1[nx][ny] >= 0 || board[nx][ny] == '#') continue; 
                dist1[nx][ny] = dist1[cur.X][cur.Y]+1;
                Q1.push({nx,ny});
            }
        }

        // �����̿� ���� BFS
        while(!Q2.empty() && (!escape)){    // !escape �����ָ� Ʋ��
            auto cur = Q2.front(); Q2.pop();
            for(int dir = 0; dir < 4; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || nx >= h || ny < 0 || ny >= w){ // ������ ����ٴ� ���� Ż�⿡ �����ߴٴ� �ǹ�. ť�� �Ÿ� ������ ���Ƿ� ���ʿ� Ż���� �ð��� ����ϸ� ��.
                    cout << dist2[cur.X][cur.Y]+1 << "\n"; 
                    escape = true;
                    break;      //4179�� ������ �ٸ��� return�� �ƴϹǷ� break�ص� while Ż���� �ȵ�
                }
                if(dist2[nx][ny] >= 0 || board[nx][ny] == '#') continue;
                if(dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.X][cur.Y]+1) continue; // ���� ���� �ð��� ���ǿ� �߰�
                dist2[nx][ny] = dist2[cur.X][cur.Y]+1;
                Q2.push({nx,ny});
            }
        } 
        if(!escape) cout << "IMPOSSIBLE" << "\n"; // ���⿡ �����ߴٴ� ���� Ż�⿡ ���������� �ǹ�.
    }
}