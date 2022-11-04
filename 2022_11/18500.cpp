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

int dx[4] = {0,0,1,-1};//좌우상하
int dy[4] = {-1,1,0,0};

int R,C,N; 
string board[101];
int high[101];

vector<vi> vis(R, vi(C, 0));
// vpii t[5];  //team
int diff[5];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> R >> C;

    for(int i=R-1; i>=0; i--)
        cin >> board[i];

    cin >> N;

    for(int i=0; i<N; i++){
        cin >> high[i];
        high[i]--;
    }

    // for(int i=0; i<R; i++)
    //     cout << board[i] << "\n";
    
    // for(int i=0; i<N; i++)
    //     cout << high[i] << " ";
    // cout << "\n";

    for(int i=0; i<N; i++){
        int x = high[i];

        int y;
        if(i%2 == 0){
            for(y=0; y<C; y++){
                if(board[x][y] == 'x'){
                    board[x][y] = '.';
                    break;
                }
            }
        }
        else{
            for(y=C-1; y>=0; y--){
                if(board[x][y] == 'x'){
                    board[x][y] = '.';
                    break;
                }
            }
        }

        //없앤 곳 기준 상하좌우 한꺼번에 살펴봐야함
        //bfs돌려서 0(바닥)까지 도달하지못하면 붕 떠있는 것이기 때문에 한칸씩 내려야함
        // 내 코드에선 올려야 함
        vis = vector<vi> (R, vi(C, 0));
        bool safe[5];
        fill(safe,safe+5,1);
        // for(auto &a : t) a.clear();
        queue<tp> q;    //x,y,team

        for(int j=1; j<=4; j++){
            int nx = x + dx[j-1];
            int ny = y + dy[j-1];
            if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if(board[nx][ny] == '.') continue;
            if(vis[nx][ny]){    //같은 팀이 이미 지나감
                safe[j] = true;
                continue;   
            }

            safe[j]=false;
            vis[nx][ny] = j;
            // t[j].push_back({nx,ny});
            q.push({nx,ny,j});

            while(!q.empty()){
                auto [a,b,team] = q.front(); q.pop();

                if(a==0) safe[team] = true;

                for(int k=0; k<4; k++){
                    int na = a + dx[k];
                    int nb = b + dy[k];
                    if(na < 0 || na >= R || nb < 0 || nb >= C) continue;
                    if(board[na][nb] == '.' || vis[na][nb]) continue;

                    vis[na][nb] = team;
                    // t[team].push_back({na,nb});
                    q.push({na,nb,team});
                }
            }
        }

        for(auto s : safe)
            cout << s << " ";
        cout << endl;       

        fill(diff, diff+5, 101);

        //모두 다 safe 될 때까지 한칸씩 내림, 내코드에선 올림
        while(!(safe[1] && safe[2] && safe[3] && safe[4])){

            string copy_board[101];
            for(int j=0; j<R; j++)
                copy_board[j] = board[j];
            
            vector<vi> copy_vis = vis;

            bool chk=false;
            for(int a=0; a<R; a++){

                for(int b=0; b<C; b++){
                    int team = copy_vis[a][b];

                    if(team && !safe[team]){    //공중에 있는 미네랄이면 옮김
                        if(copy_board[a-1][b]=='x' || a==0){//근데 더이상 옮길 수 없는 미네랄이면 safe
                        
                            // for(int i=R-1; i>=0; i--)
                            //     cout << copy_board[i] << "\n";
                            // cout << a << " " << b << endl;

                            safe[team] = true;
                            chk=true;
                            break;
                        }

                        copy_board[a][b] = '.';
                        copy_board[a-1][b] = 'x';
                        copy_vis[a][b] = 0;
                        copy_vis[a-1][b] = team;
                    }
                }
                if(chk) break;
            }

            if(!chk){
                for(int j=0; j<R; j++)
                    board[j] = copy_board[j];
                vis = copy_vis;
            }
        }
    }

    for(int i=R-1; i>=0; i--)
        cout << board[i] << "\n";
}
/* 틀린문제인데 아래 테케때문에 내가생각한 답이 맞는것같아서 오타/오역/요청에 문제변경요청해놓음
9 5
.....
xxxxx
x...x
xxx.x
x...x
x.xxx
x....
x....
x....
1
6
*/