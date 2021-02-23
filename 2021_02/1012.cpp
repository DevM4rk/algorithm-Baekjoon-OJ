#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector <ll> vl;

int T, M, N, K, X, Y, cnt;
int arr[51][51];
bool visited[51][51];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void dfs(int x, int y){
    visited[x][y] = true;

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if ( arr[nx][ny] == 1 && visited[nx][ny] == false)
            dfs(nx, ny);
    }
}

int main(){

    cin >> T;

    while(T--){
        
        cin >> M >> N >> K;
    
        memset(arr, 0, sizeof(arr));
        memset(visited, false, sizeof(visited));

        cnt = 0;

        while(K--){
            cin >> X >> Y;
            arr[Y][X] = 1;
        }

        for (int i = 0; i < N; i++) {
		    for (int j = 0; j < M; j++) {
                if( visited[i][j] == false && arr[i][j] == 1){
                    dfs(i, j);
                    cnt++;
                }
            }
        }

        cout << cnt << endl;
    }    
}