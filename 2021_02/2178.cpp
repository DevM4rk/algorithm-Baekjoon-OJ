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

int N, M;
int arr[MAX][MAX];
bool visited[MAX][MAX];
int check [MAX][MAX];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void BFS(int x, int y) {

	queue<pii> q;

    q.push(make_pair(x,y));
    visited[x][y] = true;

    while(!q.empty()){
        pii now = q.front();
        q.pop();

        int qx = now.first;
        int qy = now.second;

        if( qx == N-1 && qy == M-1 ) {
            cout << check[qx][qy];
            break;
        }

        for(int i=0; i<4; i++){
            int nx = qx + dx[i];
		    int ny = qy + dy[i];
		    if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
	    	if (arr[nx][ny] == 1 && visited[nx][ny] == false){
                visited[nx][ny] = true;
                check[nx][ny] = check[x][y] + 1;
			    q.push(make_pair(nx,ny));
		    }
        }
    }
}

int main() {
	cin >> N >> M;
	
	for(int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            scanf("%1d", &arr[i][j]);

	BFS(0,0);

}