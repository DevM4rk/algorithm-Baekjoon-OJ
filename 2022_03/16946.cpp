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
bool vis[MAX][MAX];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0 ,0 };

void BFS(int a, int b) {
	set<pii> save;
	queue<pii> q;
	q.push({a,b});
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
			if(arr[nx][ny]){
				save.insert({nx,ny});
				continue;
			}
			if(vis[nx][ny]) continue;

			vis[nx][ny] = true;
			cnt++;
			q.push({nx,ny});
		}
	}

	for(auto a : save)
		arr[a.first][a.second] += cnt;
	
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

	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cout << arr[i][j]%10;
		}
		cout << "\n";
	}

	return 0;
}