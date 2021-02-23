#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector <ll> vl;

#define MAX 1001

int N, M;
int arr[MAX][MAX];
bool visited[MAX][MAX][2];
int check [MAX][MAX] = { 0, };
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

queue<pair<pii,int>> q;

int nx;
int ny;
int qx;
        int qy;
        int qz;

// z=1 Before breaking , z=0 After breaking
void BFS(int x, int y, int z) {

    visited[x][y][z] = true;
    q.push( {{x,y}, z} );

    while(!q.empty()){

       qx = q.front().first.first;
        qy = q.front().first.second;
        qz = q.front().second;

        q.pop();

        if (qx == N - 1 && qy == M - 1) break;

        for(int i=0; i<4; i++){
            nx = qx + dx[i];
		    ny = qy + dy[i];
		    if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if ( qz==1 && arr[nx][ny]==1 ){
                visited[nx][ny][1] = true;
                check[nx][ny] = check[qx][qy] + 1;
                //cout << nx << " " << ny << " " << qz << " " << check[nx][ny] << endl;
                q.push( {{nx,ny}, 0} );
            }
	    	if (arr[nx][ny] == 0 && visited[nx][ny][qz] == false){
                visited[nx][ny][qz] = true;
                check[nx][ny] = check[qx][qy] + 1;
                //cout << nx << " " << ny << " " << qz << " " << check[nx][ny] << endl;
			    q.push( {{nx,ny}, qz} );
		    }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;
    
        for (int i = 0; i < N; i++) {
		string temp; cin >> temp;
		for (int j = 0; j < M; j++) arr[i][j] = temp[j] - '0';
	}
    check[0][0] = 1;

    BFS(0,0,1);

    if( qx != N-1 || qy != M-1) check[N-1][M-1] = -1;
    cout << check[N-1][M-1];
}
