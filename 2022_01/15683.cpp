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

int n,m,ans,camCnt;
vector<vector<int>> board1(8, vector<int>(8, 0));
vi cam;
vpii camLoc;
int dx[4] = {-1, 0, 1, 0};  // 북 동 남 서
int dy[4] = {0, 1, 0, -1};

void line(int x, int y, int roc, vector<vector<int>> &board){   //0123 북동남서    
    while(true){
        x += dx[roc];
        y += dy[roc];
        if(x < 0 || x >= n || y < 0 || y >= m) return;
        if(board[x][y] == 6) return;
        if(board[x][y] != 0) continue;
        board[x][y] = 7;
    }
}

void BTK(int cnt, vector<vector<int>> board2){ // 저장하는 보드
    if(ans==0)return;

    if(cnt == camCnt){
        int zero=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){   
                if(board2[i][j] == 0) zero++;
            }
        }

        ans = min(ans, zero);
        return;
    }

    int x,y;
    tie(x, y) = camLoc[cnt];

    if(cam[cnt] == 1){
        for(int i=0; i<4; i++){
            board1 = board2;        // board1으로 CCTV범위 체크, 다른 방향으로 찾기 위한 기존의 board 다시 받기
            line(x, y, i, board1);
            BTK(cnt+1, board1);
        }
    }
    else if(cam[cnt] == 2){
        for(int i=0; i<2; i++){
            board1 = board2;
            line(x, y, i, board1);
            line(x, y, i+2, board1);
            BTK(cnt+1, board1);
        }
    }
    else if(cam[cnt] == 3){
        for(int i=0; i<4; i++){
            board1 = board2;
            line(x, y, i, board1);
            line(x, y, (i+1)%4, board1);
            BTK(cnt+1, board1);
        }
    }
    else if(cam[cnt] == 4){
        for(int i=0; i<4; i++){
            board1 = board2;
            line(x, y, i, board1);
            line(x, y, (i+1)%4, board1);
            line(x, y, (i+2)%4, board1);
            BTK(cnt+1, board1);
        }
    }
    else if(cam[cnt] == 5){
        board1 = board2;
        for(int i=0; i<4; i++) line(x, y, i, board1);
        BTK(cnt+1, board1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    int num;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> num;
            board1[i][j] = num;
            if(num >= 1 && num <= 5){
                cam.push_back(num);
                camLoc.push_back({i,j});
            }
            if(num == 0) ans++;
        }
    }
    camCnt = cam.size();
    
    BTK(0, board1);

    cout << ans;
}