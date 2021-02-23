#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector <ll> vl;

#define MAX 101

int N, M, H;
int arr[MAX][MAX][MAX];
bool visited[MAX][MAX][MAX];
int check [MAX][MAX][MAX] = { 0, };
int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

queue<pair<pii, int>> q;

int nx;
int ny;
int nz;

void BFS(int x, int y, int z) {

    visited[x][y][z] = true;

    while(!q.empty()){

        int qx = q.front().first.first;
        int qy = q.front().first.second;
        int qz = q.front().second;

        q.pop();

        for(int i=0; i<6; i++){
            nx = qx + dx[i];
		    ny = qy + dy[i];
		    nz = qz + dz[i];

		    if (nx < 0 || nx >= N || ny < 0 || ny >= M || nz < 0 || nz >= H) continue;
	    	if (arr[nx][ny][nz] == 0 && visited[nx][ny][nz] == false){
                visited[nx][ny][nz] = true;
                check[nx][ny][nz] = check[qx][qy][qz] + 1;
                //cout << nx << " " << ny << " " << nz << " " << check[nx][ny][nz] << endl;
			    q.push(make_pair(make_pair(nx,ny),nz));
		    }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    
	cin >> M >> N >> H;

	queue<pair<pii, int>> now;

    for(int k=0; k<H; k++){
        for(int i=0; i<N; i++){
            for (int j=0; j<M; j++){
                cin >> arr[i][j][k];
                if ( arr[i][j][k] == 1 ) {
                    q.push(make_pair(make_pair(i,j),k));
                }
            }
        }
    }

    BFS(q.front().first.first, q.front().first.second, q.front().second);

    for(int k=0; k<H; k++){   
        for(int i=0; i<N; i++){
            for (int j=0; j<M; j++){
                if( arr[i][j][k] == 0 && !visited[i][j][k] ){
                    check[nx][ny][nz+1] = -1;
                    break;
                }
            }
        }
    }

    //cout << nx << ny << nz+1 << endl;
    cout << check[nx][ny][nz+1];
}