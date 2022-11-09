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

int n,m,x,y,k;
int board[21][21];
deque<int> dice_x(4,0); //세로
deque<int> dice_y(3,0); //가로

int dx[] = {0,0,0,-1,1};
int dy[] = {0,1,-1,0,0};    // _동서북남

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m >> x >> y >> k;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> board[i][j];

    for(int i=0; i<k; i++){
        int dir; cin >> dir;

        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

        if(dir==1){
            dice_y.push_front(dice_x.back());
            dice_x[3] = dice_y.back();
            dice_y.pop_back();
            dice_x[1] = dice_y[1];
        }
        else if(dir==2){
            dice_y.push_back(dice_x.back());
            dice_x[3] = dice_y.front();
            dice_y.pop_front();
            dice_x[1] = dice_y[1];
        }
        else if(dir==3){
            dice_x.push_back(dice_x.front());
            dice_x.pop_front();
            dice_y[1] = dice_x[1];
        }
        else if(dir==4){
            dice_x.push_front(dice_x.back());
            dice_x.pop_back();
            dice_y[1] = dice_x[1];
        }

        if(board[nx][ny]==0){
            board[nx][ny] = dice_x.back();
        }
        else{
            dice_x[3] = board[nx][ny];
            board[nx][ny] = 0;
        }

        // for(auto d : dice_x) cout << d << " ";
        // cout << endl;
        // for(auto d : dice_y) cout << d << " ";
        // cout << endl;

        x = nx;
        y = ny;

        cout << dice_x[1] << "\n";
    }
}