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
int zeroCnt[MAX][MAX];
bool vis[MAX][MAX];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0 ,0 };

void BFS(int a, int b) {
	queue<pii> q, save;
	q.push({a,b});
	save.push({a,b});
	vis[a][b] = true;
	int cnt=1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		//cout << x << " " << y << endl;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if(arr[nx][ny] || vis[nx][ny]) continue;

			vis[nx][ny] = true;
			cnt++;
			q.push({nx,ny});
			save.push({nx,ny});
		}
	}

	while(!save.empty()){
		auto cur = save.front(); save.pop();
		zeroCnt[cur.first][cur.second] = cnt;
	}
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	    
    for (int i = 0; i < N; i++) {
		string temp; cin >> temp;
		for (int j = 0; j < M; j++) arr[i][j] = temp[j] - '0';
	}

	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			if(arr[i][j] == 0 && !vis[i][j]){
				BFS(i,j);
			}
		}
	}

	cout << "\n";
	
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cout << zeroCnt[i][j]%10;
		}
		cout << "\n";
	}

	cout << "\n";

	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			for(int k=0; k<4; k++){
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
				arr[i][j] += zeroCnt[nx][ny];
			}
			cout << arr[i][j]%10;
		}
		cout << "\n";
	}

	return 0;
}