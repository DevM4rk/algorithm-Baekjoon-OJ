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
1�� ��� ã�ƾ���
1�� �ΰ���� BFS�� �ΰ��� ������ �ҵ�

�����Է�3 ����
BFS(0,0);
BFS(N-1,M-1);

�� �ƴ϶�

1�� ã�� ť�� �־� ���´ٸ�?
 �װ��� ����

1�� ��������

���� 0 �� ��� True�� �ٲٸ鼭 
(�̰��ʿ������)���� 1, -1�� ��� continue;

�̷��� �� �ϰ� 0 �� ���� �ִ� ���
cout << "-1";

*/