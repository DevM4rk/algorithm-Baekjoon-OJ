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
bool visited[MAX][MAX][2] = { false, };
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0 ,0 };


// z=1 Before breaking , z=0 After breaking

int BFS() {
	queue<pair<pii, pii>> q;
	q.push( { {0,0}, {1,1} } );
	visited[0][0][1] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int wall = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();

		if (x == N - 1 && y == M - 1) return cnt;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (arr[nx][ny] == 1 && wall == 1) {
				visited[nx][ny][0] = true;
                q.push( {{nx,ny}, {0, cnt+1}} );
			}
			else if (arr[nx][ny] == 0 && !visited[nx][ny][wall]) {
				visited[nx][ny][wall] = true;
			    q.push( { {nx,ny}, {wall, cnt+1}} );
			}
		}
	}
	return -1;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	    
    for (int i = 0; i < N; i++) {
		string temp; cin >> temp;
		for (int j = 0; j < M; j++) arr[i][j] = temp[j] - '0';
	}
	cout << BFS();

	return 0;
}