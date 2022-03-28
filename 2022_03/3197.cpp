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

int n,m,day;
int sx,sy;
bool vis[1501][1501];
char arr[1501][1501];
queue<pii> nextwater, water, nextduck, duck;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

bool meet(){

    while(!duck.empty()){
        auto cur = duck.front(); duck.pop();
        int x = cur.first;
        int y = cur.second;

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(vis[nx][ny]) continue;

            vis[nx][ny] = 1;

            if(arr[nx][ny] == 'X')
                nextduck.push({nx,ny});
            else if(arr[nx][ny] == 'L') 
                return true;
            else
                duck.push({nx,ny});
        }
    }    

    return false;
}

void melt(){

    while(!water.empty()){
        auto cur = water.front(); water.pop();
        int x = cur.first;
        int y = cur.second;

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

            if(arr[nx][ny] == 'X'){
                arr[nx][ny] = '.';
                nextwater.push({nx,ny});
            }
        }
    }    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];

            if(arr[i][j] != 'X'){
                water.push({i,j});
            }

            if(arr[i][j] == 'L'){
                sx = i, sy = j;
            }
        }
    }

    duck.push({sx, sy});
    vis[sx][sy] = true;
    
    while(true){
        if(meet()){
            cout << day;
            break;
        }
        day++;

        melt();

        water = nextwater;
        duck = nextduck;

        nextwater = queue<pii>();
        nextduck = queue<pii>();
    }
}