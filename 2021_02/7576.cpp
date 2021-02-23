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

#define MAX 1001

int N, M;
int arr[MAX][MAX];
bool visited[MAX][MAX];
int check [MAX][MAX] = { 0, };
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
queue<pii> q;

int nx;
int ny;

void BFS(int x, int y) {

    visited[x][y] = true;

    while(!q.empty()){
        pii now = q.front();
        q.pop();

        int qx = now.first;
        int qy = now.second;

        for(int i=0; i<4; i++){
            nx = qx + dx[i];
		    ny = qy + dy[i];
		    if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
	    	if (arr[nx][ny] == 0 && visited[nx][ny] == false){
                visited[nx][ny] = true;
                check[nx][ny] = check[qx][qy] + 1;
                //cout << nx << " " << ny << " " << check[nx][ny] << endl;
			    q.push(make_pair(nx,ny));
		    }
        }
    }
}

int main() {
    	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    
	cin >> M >> N;

	pii now;

	for(int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            cin >> arr[i][j];
            if ( arr[i][j] == 1 ) {
                q.push(make_pair(i,j));
                now = q.front();
            }
        }
    }

    BFS(now.first, now.second);

    for(int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            if( arr[i][j] == 0 && !visited[i][j] ){
                check[nx][ny+1] = -1;
                break;
            }
        }
    }

    //cout << nx << ny+1 << endl;
    cout << check[nx][ny+1];
}

/*
1을 모두 찾아야함
1이 두개라면 BFS를 두개를 돌려야 할듯

예제입력3 기준
BFS(0,0);
BFS(N-1,M-1);

가 아니라

1을 찾아 큐에 넣어 놓는다면?
 그것이 정답

1을 기준으로

만일 0 일 경우 True로 바꾸면서 
(이건필요없을듯)만일 1, -1일 경우 continue;

이렇게 다 하고도 0 이 남아 있는 경우
cout << "-1";

*/